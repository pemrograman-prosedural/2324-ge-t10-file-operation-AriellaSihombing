// 12S23005 - Ariella U.C Sihombing
// 12S23046 - Anastasya T.B. Siahaan

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "./libs/dorm.h"
#include "./libs/student.h"
#include "./libs/repository.h"

#define MAX_DORMS 100
#define MAX_STUDENTS 1000

int main(int argc, char **argv) {
    struct student_t students[MAX_STUDENTS];
    dorm_t dorms[MAX_DORMS];
    unsigned short dorm_size = 0;
    unsigned short students_size = 0;
    char line[100];
    const char *penghubung = "#";

    while (1) {
        if (fgets(line, sizeof(line), stdin) == NULL) {
            fprintf(stderr, "Error reading input\n");
            break;
        }

        // Hapus karakter newline jika ada
        line[strcspn(line, "\n")] = '\0';

        if (strcmp(line, "---") == 0) {
            break;
        } else if (strcmp(line, "student-print-all-detail") == 0) {
            for (short j = 0; j < students_size; j++) {
                printf("%s|%s|%s|%s|unassigned\n", students[j].id, students[j].name, students[j].year, students[j].gender == GENDER_MALE? "male" : "female");
            }
        } else if (strcmp(line, "dorm-print-all-detail") == 0) {
            for (short j = 0; j < dorm_size; j++) {
                print_dorm_all_detail(dorms[j]);
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

                if (students_size >= MAX_STUDENTS) {
                    fprintf(stderr, "Maximum number of students reached\n");
                    continue;
                }

                if (strcmp(token, "male") == 0) {
                    students[students_size++] = create_student(id, name, year, GENDER_MALE);
                } else if (strcmp(token, "female") == 0) {
                    students[students_size++] = create_student(id, name, year, GENDER_FEMALE);
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
                    dorms[dorm_size++] = create_dorm(name, capacity, GENDER_MALE);
                } else if (strcmp(token, "female") == 0) {
                    dorms[dorm_size++] = create_dorm(name, capacity, GENDER_FEMALE);
                }
            }
        }
    }

    return 0;
}
