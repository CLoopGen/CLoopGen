#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>

char **filelist;
char **files;
int count = 0;
int i = 0;
int j = 0;

void init_vars() {
    size_t data_size = 1 << 20; // ~1MB of input data
    count = (data_size / sizeof(char*)) / 2; // Adjust to ensure enough space

    files = calloc(count, sizeof(char*));
    filelist = calloc(count, sizeof(char*));

    for (int idx = 0; idx < count; idx++) {
        files[idx] = malloc(32 * sizeof(char));
        if ((idx % 3) == 0) {
            strcpy(files[idx], "-exclude");
        } else {
            sprintf(files[idx], "file%d.txt", idx);
        }
    }

    j = 0;
}