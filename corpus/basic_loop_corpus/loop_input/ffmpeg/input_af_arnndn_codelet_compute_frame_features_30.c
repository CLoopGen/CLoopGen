#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

#define ARRAY_SIZE 64000000

float *features;
float *ceps_0;
float *ceps_1;
float *ceps_2;

void init_vars() {
    features = (float*)aligned_alloc(32, sizeof(float) * (22 + 6 + 6));
    ceps_0 = (float*)aligned_alloc(32, sizeof(float) * ARRAY_SIZE);
    ceps_1 = (float*)aligned_alloc(32, sizeof(float) * ARRAY_SIZE);
    ceps_2 = (float*)aligned_alloc(32, sizeof(float) * ARRAY_SIZE);

    for (int i = 0; i < 6; i++) {
        ceps_0[i] = 1.0f;
        ceps_1[i] = 2.0f;
        ceps_2[i] = 3.0f;
    }

    for (int i = 6; i < ARRAY_SIZE; i++) {
        ceps_0[i] = 0.0f;
        ceps_1[i] = 0.0f;
        ceps_2[i] = 0.0f;
    }

    for (int i = 0; i < (22 + 6 + 6); i++) {
        features[i] = 0.0f;
    }
}