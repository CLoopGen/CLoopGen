#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

float *output;
float a;
float b;
int i;

void init_vars() {
    const size_t array_size = 1792;
    output = (float *)aligned_alloc(32, array_size * sizeof(float));
    a = 1.5f;
    b = 2.5f;
    i = 0;

    for (size_t idx = 0; idx < array_size; idx++) {
        output[idx] = 1.0f + (float)idx;
    }
}