// 12S23005 - Ariella U.C Sihombing
// 12S23046 - Anastasya T.B. Siahaan

#include <stdio.h>
#include "./libs/dorm.h"
#include "./libs/student.h"
#include "./libs/repository.h"

#define MAX_DORMS 100
#define MAX_STUDENTS 1000

int main(int _argc, char **_argv)
{
    struct student_t *students = malloc(MAX_STUDENTS * sizeof(struct student_t));
    if (!students) {
        fprintf(stderr, "Memory allocation failed for students\n");
        return 1;
    }
    dorm_t *dorms = malloc(MAX_DORMS * sizeof(dorm_t));
    if (!dorms) {
        fprintf(stderr, "Memory allocation failed for dorms\n");
        free(students);
        return 1;
    }

    unsigned short dorm_size = 0;
    unsigned short students_size = 0;
    char line[100];
    char *penghubung = "#";

    while (1) {
        line[0] = '\0';
        fgets(line, 100, stdin);
        fflush(stdin);

        int len = strlen(line);
        for (short i = 0; i < len; i++) {
            if (line[i] == '\r' || line[i] == '\n') {
                for (short b = i; b < len; b++) {
                    line[b] = line[b + 1];
                }
                len--;
                i--;
            }
        }

        if (strcmp(line, "---") == 0) {
            break;
        } else if (strcmp(line, "student-print-all") == 0) {
            for (short j = 0; j < students_size; j++) {
                printf("%s|%s|%s|%s\n", students[j].id, students[j].name, students[j].year, students[j].gender == GENDER_MALE? "male" : "female");
            }
        } else if (strcmp(line, "student-print-all-detail") == 0) {
            for (short j = 0; j < students_size; j++) {
                printf("%s|%s|%s|%s|unassigned\n", students[j].id, students[j].name, students[j].year, students[j].gender == GENDER_MALE? "male" : "female");
            }
        } else {
            char *token = strtok(line, penghubung);
            if (strcmp(token, "student-add") == 0) {
                token = strtok(NULL, penghubung);
                char *id = token;
                token = strtok(NULL, penghubung);
                char *name = token;
                token = strtok(NULL, penghubung);
                char *year = token;
                token = strtok(NULL, penghubung);

                if (students_size > 0) {
                    students = (struct student_t *)realloc(students, (students_size + 1) * sizeof(struct student_t));
                    if (!students) {
                        fprintf(stderr, "Memory reallocation failed for students\n");
                        free(dorms);
                        return 1;
                    }
                }

                if (strcmp(token, "male") == 0) {
                    students[students_size] = create_student(id, name, year, GENDER_MALE);
                    students_size++;
                } else if (strcmp(token, "female") == 0) {
                    students[students_size] = create_student(id, name, year, GENDER_FEMALE);
                    students_size++;
                }
            } else if (strcmp(token, "dorm-print-all") == 0) {
                for (short j = 0; j < dorm_size; j++) {
                    print_dorm(dorms[j]);
                }
            } else if (strcmp(token, "dorm-print-all-detail") == 0) {
                for (short j = 0; j < dorm_size; j++) {
                    print_dorm_all_detail(dorms[j]);
                }
            } else if (strcmp(token, "dorm-add") == 0) {
                token = strtok(NULL, penghubung);
                char *name = token;
                token = strtok(NULL, penghubung);
                unsigned short capacity = atoi(token);
                token = strtok(NULL, penghubung);

                if (dorm_size >= MAX_DORMS) {
                    fprintf(stderr, "Maximum number of dorms reached\n");
                    continue;
                }

                if (strcmp(token, "male") == 0) {
                    dorms[dorm_size] = create_dorm(name, capacity, GENDER_MALE);
                    dorm_size++;
                } else if (strcmp(token, "female") == 0) {
                    dorms[dorm_size] = create_dorm(name, capacity, GENDER_FEMALE);
                    dorm_size++;
                }
            }
        }
    }

    free(students);
    free(dorms);

    return 0;
}