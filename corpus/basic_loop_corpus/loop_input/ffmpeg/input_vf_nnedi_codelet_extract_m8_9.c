#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int stride;
int xdia;
int ydia;
float *input;
uint8_t *srcp;
int64_t sum;
int64_t sumsq;
int y;
int x;

void init_vars() {
    xdia = 4096;
    ydia = 4096;
    stride = xdia;

    srcp = (uint8_t*)aligned_alloc(32, (size_t)stride * ydia * 2);
    input = (float*)aligned_alloc(32, (size_t)xdia * ydia * sizeof(float));

    for (int i = 0; i < stride * ydia * 2; i++) {
        srcp[i] = (uint8_t)(i % 256);
    }

    sum = 0;
    sumsq = 0;
}

void loop();