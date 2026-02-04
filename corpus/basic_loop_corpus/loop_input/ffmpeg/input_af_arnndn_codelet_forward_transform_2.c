#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef struct AVComplexFloat {
    float re;
    float im;
} AVComplexFloat;

float *in;
AVComplexFloat x[960];

void init_vars() {
    const int size = 2 * (120 << 2); // i.e., 2 * 480 = 960
    in = (float *)aligned_alloc(32, size * sizeof(float));
    if (!in) {
        exit(1);
    }
    for (int i = 0; i < size; i++) {
        in[i] = (float)(i * 2.5);
    }
    for (int i = 0; i < 960; i++) {
        x[i].re = 0.0f;
        x[i].im = 0.0f;
    }
}