#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <time.h>
#include <math.h>

void *B;
int ldb;
int i;
int j;
int n1;
int n2;
float alpha_real;
float alpha_imag;

static float *B_data;

void init_vars() {
    const int element_size = 2; // real and imaginary parts
    const size_t target_bytes = 64 * 1024 * 1024; // Aim for ~64 MB to ensure measurable runtime (~0.01 sec on modern CPU)
    
    n1 = 4096;
    n2 = 4096;
    ldb = n1;

    size_t total_elements = (size_t)ldb * n2 * element_size;
    size_t total_bytes = total_elements * sizeof(float);

    if (total_bytes < target_bytes) {
        double scale = sqrt((double)target_bytes / total_bytes);
        n1 = (int)(n1 * scale);
        n2 = (int)(n2 * scale);
        ldb = n1;
        total_elements = (size_t)ldb * n2 * element_size;
    }

    B_data = (float *)aligned_alloc(32, total_elements * sizeof(float));
    B = (void *)B_data;

    for (size_t idx = 0; idx < total_elements; idx++) {
        B_data[idx] = (float)(idx % 128) / 64.0f - 1.0f; // Fill with smooth random-like values
    }

    alpha_real = 0.8f;
    alpha_imag = 0.6f;

    i = 0;
    j = 0;
}