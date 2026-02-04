#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <time.h>

uint8_t *srcp;
int stride;
int xdia;
int ydia;
int16_t *input;
int sum;
int sumsq;
int y;
int x;

void init_vars() {
    xdia = 2048;
    ydia = 2048;
    stride = xdia;

    size_t src_size = (size_t)ydia * stride * 2;
    srcp = (uint8_t*)aligned_alloc(32, src_size);
    if (!srcp) exit(1);

    size_t input_size = (size_t)ydia * xdia;
    input = (int16_t*)aligned_alloc(32, input_size * sizeof(int16_t));
    if (!input) exit(1);

    for (size_t i = 0; i < src_size; i++) {
        srcp[i] = (uint8_t)(i % 256);
    }

    for (size_t i = 0; i < input_size; i++) {
        input[i] = 0;
    }

    sum = 0;
    sumsq = 0;
}