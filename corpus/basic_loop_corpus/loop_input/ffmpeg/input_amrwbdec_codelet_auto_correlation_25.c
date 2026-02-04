#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

float *diff_isf;
float mean;
int lag;
int i;
float sum;

void init_vars() {
    size_t data_size = 1 << 20; // ~4MB of float data (1M elements)
    diff_isf = (float *)calloc(data_size, sizeof(float));
    if (!diff_isf) {
        exit(1);
    }

    for (size_t idx = 0; idx < data_size; idx++) {
        diff_isf[idx] = (float)(rand() % 1000) / 100.0f;
    }

    mean = 5.0f;
    lag = 1;
    i = 0;
    sum = 0.0f;
}