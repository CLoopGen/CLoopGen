#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef struct AVComplexFloat {
    float re;
    float im;
} AVComplexFloat;

AVComplexFloat *X = NULL;
float normf[481];

void init_vars() {
    const int size = (120 << 2) + 1; // i.e., 481
    X = aligned_alloc(32, size * sizeof(AVComplexFloat));
    for (int i = 0; i < size; i++) {
        X[i].re = 1.0f;
        X[i].im = 1.0f;
        normf[i] = 2.0f;
    }
}