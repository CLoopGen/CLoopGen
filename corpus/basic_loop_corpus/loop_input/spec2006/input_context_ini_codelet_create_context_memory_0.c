#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>

int number_of_slices;
int ***initialized;
int i;
int j;
int k;

void init_vars() {
    number_of_slices = 1024 * 64; // Approximately 64K slices to target 0.01s runtime

    initialized = (int***)calloc(3, sizeof(int**));
    for (k = 0; k < 3; k++) {
        initialized[k] = (int**)calloc(4, sizeof(int*));
        for (i = 0; i < 4; i++) {
            initialized[k][i] = (int*)calloc(number_of_slices, sizeof(int));
        }
    }
}