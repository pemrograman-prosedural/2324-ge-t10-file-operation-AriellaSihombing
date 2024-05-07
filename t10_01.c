// 12S23005 - Ariella U.C Sihombing
// 12S23046 - Anastasya T.B. Siahaan

#include <stdio.h>
#include "./libs/repository.h" // Include header file repository.h

int line_count(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        fprintf(stderr, "Cannot open file\n");
        return -1;
    }

    char buffer[256];
    int lines = 0;
    while (fgets(buffer, sizeof(buffer), file)) {
        lines++;
    }

    fclose(file);
    return lines;
}

// Definisikan main di sini jika repository.c ingin digunakan sebagai program mandiri
int main(int argc, char **argv) {
    int count = line_count("example.txt");
    if (count >= 0) {
        printf("Number of lines in file: %d\n", count);
    }

    return 0;
}