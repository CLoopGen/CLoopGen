#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

void *B;
int ldb;
int i;
int j;
int n1;
int n2;
float alpha_real;
float alpha_imag;

void init_vars() {
    alpha_real = 1.5f;
    alpha_imag = 0.8f;

    n1 = 2048;
    n2 = 2048;
    ldb = n2;

    size_t total_elements = 2 * ldb * n1;
    float *B_data = (float *)aligned_alloc(32, total_elements * sizeof(float));
    if (!B_data) {
        exit(1);
    }

    for (size_t idx = 0; idx < total_elements; idx++) {
        B_data[idx] = (float)(idx % 128) / 64.0f;
    }

    B = (void *)B_data;
}