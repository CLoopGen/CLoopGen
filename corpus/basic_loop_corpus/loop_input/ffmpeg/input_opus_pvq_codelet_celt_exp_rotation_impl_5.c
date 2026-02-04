#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <math.h>

uint32_t len;
uint32_t stride;
float c;
float s;
float *Xptr;
int i;

void init_vars() {
    len = 1 << 20; // 1 million elements
    stride = 1 << 9; // 512, ensuring len - stride is positive and significant
    float angle = 0.785398f; // approx. pi/4
    s = sinf(angle);
    c = cosf(angle);

    Xptr = (float*)aligned_alloc(32, sizeof(float) * len);
    if (!Xptr) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    for (uint32_t j = 0; j < len; j++) {
        Xptr[j] = (float)(j % 1000) / 1000.0f;
    }
}