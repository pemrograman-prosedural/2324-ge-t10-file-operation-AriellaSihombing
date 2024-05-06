#include "dorm.h"
#define MAX_DORMS 100
/**
 * @brief Define the complete function definition here. Be sure to enlist the prototype of each function
 * defined here in the corresponding header file.
 *
 */
//  membuat struct nama, capasity, gender, resident
 struct dorm_t create_dorm (char *_name, unsigned short _capacity , enum gender_t _gender ){
    struct dorm_t dorm_;
    strcpy(dorm_.name, _name);
    dorm_.capacity = _capacity;
    dorm_.residents_num = 0;
    if (_gender == GENDER_MALE){
        dorm_.gender = GENDER_MALE;
    }
    else if (_gender == GENDER_FEMALE){
        dorm_.gender = GENDER_FEMALE;
    }
    
    return dorm_;
 }

    void print_dorm (struct dorm_t dorm){
        printf("%s|%d|", dorm.name, dorm.capacity);
        if (dorm.gender == GENDER_FEMALE){
            printf("female\n");
        }
        else{
            printf("male\n");
        }

    }

    void print_dorm_all_detail ( dorm_t dorm_){
        printf ( "%s|%d|", dorm_.name, dorm_.capacity);
        ( dorm_.gender == GENDER_MALE) ? 
        printf ( "male|") : printf ( "female|");
        printf ( "%d\n", dorm_.residents_num);
        fflush ( stdout);
    }

short dormindex(char* _name, dorm_t dorm_, int length) {
    for (int i = 0; i < length; i++) {
        if (strcmp(_name, dorm_.name) == 0) {
            return i;
        }
    }
    return -1; // Pernyataan return tambahan untuk menangani kasus ketika tidak ada nama yang cocok
}
