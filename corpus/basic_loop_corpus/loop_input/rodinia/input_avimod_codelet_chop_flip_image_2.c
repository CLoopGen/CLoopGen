#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int height_new;
int width_new;
int i;
int j;
float *result;
float *result_converted;

void init_vars() {
    width_new = 512;
    height_new = 512;

    size_t result_size = (size_t)width_new * height_new * sizeof(float);
    result = (float *)aligned_alloc(32, result_size);
    result_converted = (float *)aligned_alloc(32, result_size);

    for (size_t idx = 0; idx < (size_t)width_new * height_new; idx++) {
        result[idx] = (float)(idx % 1000) / 10.0f;
    }
}