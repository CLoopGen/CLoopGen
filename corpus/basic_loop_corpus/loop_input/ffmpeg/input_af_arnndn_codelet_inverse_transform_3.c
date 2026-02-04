#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef struct AVComplexFloat {
    float re;
    float im;
} AVComplexFloat;

AVComplexFloat *in;
AVComplexFloat x[960];

void init_vars() {
    const int total_size = (120 << 2) + 1; // 481 elements
    in = aligned_alloc(32, total_size * sizeof(AVComplexFloat));
    for (int i = 0; i < total_size; i++) {
        in[i].re = (float)(i * 2);
        in[i].im = (float)(i * 2 + 1);
    }
}