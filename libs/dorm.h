#ifndef DORM_H
#define DORM_H

#include "gender.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

/**
 * @brief define your structure, enums, globally accessible variables, and function prototypes here.
 * The actual function implementation should be defined in the corresponding source file.
 *
 */


struct dorm_t
{
  char name[20];
  unsigned short capacity;
  enum gender_t gender;
  unsigned short residents_num;
};

struct dorm_t create_dorm (char *_name, unsigned short _capacity, enum gender_t _gender);
void print_dorm (struct dorm_t dorm);
void print_dorm_all_detail ( struct dorm_t dorm_);
short dormindex ( char* _name, struct dorm_t dorms, int length);
typedef struct dorm_t dorm_t;

#endif
