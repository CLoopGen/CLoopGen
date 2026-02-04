#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <time.h>
#include <math.h>

#define DATA_SIZE_MB 64

float *B_data;
void *B;
int ldb;
int i;
int j;
int n1;
int n2;
float alpha_real;
float alpha_imag;

void init_vars() {
    const size_t total_elements = (DATA_SIZE_MB * (1 << 20)) / sizeof(float);
    B_data = (float*)aligned_alloc(32, total_elements * sizeof(float));
    if (!B_data) {
        exit(1);
    }

    ldb = (int)sqrt(total_elements / 2);
    n1 = ldb;
    n2 = ldb;

    while ((size_t)(2 * ldb * n1) > total_elements) {
        n1--;
    }

    for (size_t idx = 0; idx < total_elements; idx++) {
        B_data[idx] = (float)(idx % 128) / 64.0f;
    }

    B = (void*)B_data;

    alpha_real = 1.5f;
    alpha_imag = 0.8f;
}