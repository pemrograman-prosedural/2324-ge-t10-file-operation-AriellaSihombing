#include "repository.h"
#include <stdio.h>
#include <string.h>

/**
 * @brief Define the complete function definition here. Be sure to enlist the prototype of each function
 * defined here in the corresponding header file.
 *
 */
short line_count(char *line){
    filename [strcspn(filename, "\n")] = 0;
    FILE *file = fopen(filename, "r");
    short count = 0;
    char chr = getc(ptr);

    while (chr != EOF){
        if (chr == '\n'){
            count++;
        }
        chr = getc(ptr);
    }
    fclose(file);
    return count;
}