#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <math.h>

typedef struct AVComplexFloat {
    float re;
    float im;
} AVComplexFloat;

#define DATA_SIZE (64 * 1024 * 1024) // ~64MB of AVComplexFloat data
#define ARRAY_LEN ((DATA_SIZE / sizeof(AVComplexFloat)) > (120*4+1) ? (120*4+1) : DATA_SIZE / sizeof(AVComplexFloat))

AVComplexFloat *X;
AVComplexFloat *P;
float rf[481];

void init_vars() {
    X = (AVComplexFloat*)aligned_alloc(32, sizeof(AVComplexFloat) * ARRAY_LEN);
    P = (AVComplexFloat*)aligned_alloc(32, sizeof(AVComplexFloat) * ARRAY_LEN);

    for (int i = 0; i < ARRAY_LEN; i++) {
        X[i].re = (float)(i % 100) * 0.1f;
        X[i].im = (float)(i % 100) * 0.2f;
        P[i].re = (float)(i % 50) * 0.3f;
        P[i].im = (float)(i % 50) * 0.4f;
    }

    for (int i = 0; i < 481; i++) {
        rf[i] = (float)(i % 25) * 0.05f;
    }
}