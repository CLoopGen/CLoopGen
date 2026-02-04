#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <math.h>

#define DATA_SIZE_MB 64
#define TOTAL_ELEMENTS (DATA_SIZE_MB * (1 << 20) / sizeof(float))

float *delta;
float *target;
float *output;
int nj;
int j;
float o;
float t;
float errsum;

void init_vars() {
    nj = TOTAL_ELEMENTS - 1;  

    delta = (float*)aligned_alloc(32, TOTAL_ELEMENTS * sizeof(float));
    target = (float*)aligned_alloc(32, TOTAL_ELEMENTS * sizeof(float));
    output = (float*)aligned_alloc(32, TOTAL_ELEMENTS * sizeof(float));

    for (int i = 0; i < TOTAL_ELEMENTS; i++) {
        target[i] = (float)(rand() % 100) / 100.0f;
        output[i] = (float)(rand() % 100) / 100.0f;
        delta[i] = 0.0f;
    }

    j = 0;
    o = 0.0f;
    t = 0.0f;
    errsum = 0.0f;
}