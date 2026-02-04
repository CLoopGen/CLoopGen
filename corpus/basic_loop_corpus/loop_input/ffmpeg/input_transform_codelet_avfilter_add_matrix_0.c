#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

float *m1;
float *m2;
float *result;
int i;

#define DATA_SIZE 64000000

void init_vars() {
    m1 = (float*)aligned_alloc(32, DATA_SIZE * sizeof(float));
    m2 = (float*)aligned_alloc(32, DATA_SIZE * sizeof(float));
    result = (float*)aligned_alloc(32, DATA_SIZE * sizeof(float));

    for (int j = 0; j < DATA_SIZE; j++) {
        m1[j] = (float)(j % 100) + 1.0f;
        m2[j] = (float)((j + 5) % 100) + 1.0f;
    }
}