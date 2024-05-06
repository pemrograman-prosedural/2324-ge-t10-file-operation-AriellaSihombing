#include "student.h"

/**
 * @brief Define the complete function definition here. Be sure to enlist the prototype of each function
 * defined here in the corresponding header file.
 *
 */
struct student_t create_student (char *_id, char *_name, char *_year, enum gender_t _gender)
{
    struct student_t student_;
    memset(student_.id, 0, sizeof(student_.id));
    memset(student_.name, 0, sizeof(student_.name));
    memset(student_.year, 0, sizeof(student_.year));
    student_.gender = _gender;
    strcpy(student_.id, _id);
    strcpy(student_.name, _name);
    strcpy(student_.year, _year);
    student_.dorm = NULL;
    return student_;
}
void print_student (struct student_t _student) {
  printf("%s|%s|%s|", _student.id, _student.name, _student.year);
  if (_student.gender == GENDER_MALE) {
    printf("male");
  } else if (_student.gender == GENDER_FEMALE) {
    printf("female");
  }
  if (_student.dorm == NULL) {
    printf("\n");
  } else {
    printf("%s\n", _student.dorm->name);
  }
}



void assign_student (struct student_t *_student, struct dorm_t *_dorm, int dorm_size, int student_size) 
{
    for (int i = 0; i < student_size; i++){
        for (int j = 0; j < dorm_size; j++){
            if (_student[i].gender == _dorm[j].gender){
                if (_dorm[j].capacity != _dorm[j].residents_num){
                    _student[i].dorm = malloc(sizeof(struct dorm_t)); 
                    strcpy(_student[i].dorm->name, _dorm[j].name);
                    _dorm[j].residents_num++;
                }
            }
        }
    }
}

void print_student_all_detail (struct student_t _student) {
  printf("%s|%s|%s|", _student.id, _student.name, _student.year);
}