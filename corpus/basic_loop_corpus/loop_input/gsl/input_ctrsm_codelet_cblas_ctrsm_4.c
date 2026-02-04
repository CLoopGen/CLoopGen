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
    n2 = 65536 / 4; 

    ldb = n2;

    size_t total_elements = (size_t)ldb * n1;
    size_t total_bytes = total_elements * 2 * sizeof(float);

    float *B_float = (float *)aligned_alloc(32, total_bytes);
    if (!B_float) {
        exit(1);
    }

    for (size_t idx = 0; idx < total_elements * 2; idx++) {
        B_float[idx] = (float)(idx % 128) * 0.1f;
    }

    B = (void *)B_float;
}