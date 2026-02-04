#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <time.h>

#define ISF_SIZE 20
#define DIFF_ISF_SIZE 14
#define DATA_SIZE_MB 64
#define LOOP_ITERATIONS (16 - 2)

float isf[ISF_SIZE];
float diff_isf[DIFF_ISF_SIZE];
int i;

void init_vars() {
    // Initialize isf with non-zero values to simulate realistic data
    for (int idx = 0; idx < ISF_SIZE; idx++) {
        isf[idx] = (float)(idx * 3.14159 + 1.0);
    }

    // Zero out diff_isf before use
    for (int idx = 0; idx < DIFF_ISF_SIZE; idx++) {
        diff_isf[idx] = 0.0f;
    }

    // Initialize loop index
    i = 0;
}