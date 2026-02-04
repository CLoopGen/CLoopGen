#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <inttypes.h>
#include <string.h>
#include <time.h>

double *v0;
double *v1;
double *v2;
double *v3;
double *w;
int i;
int len2;
double sum00;
double sum10;
double sum20;
double sum30;
double w_val0;
double sum01;
double sum11;
double sum21;
double sum31;
double w_val1;

void init_vars() {
    const size_t total_data_size = 64 * 1024 * 1024; // ~64MB total for all arrays to target ~0.01s runtime
    const size_t element_size = sizeof(double);
    const size_t num_elements_per_array = total_data_size / (5 * element_size); // 5 arrays: v0, v1, v2, v3, w
    const size_t aligned_len2 = num_elements_per_array & (~1ULL); // Ensure even for 2*i+1 access

    len2 = (int)aligned_len2;

    v0 = (double*)aligned_alloc(32, len2 * 2 * element_size);
    v1 = (double*)aligned_alloc(32, len2 * 2 * element_size);
    v2 = (double*)aligned_alloc(32, len2 * 2 * element_size);
    v3 = (double*)aligned_alloc(32, len2 * 2 * element_size);
    w  = (double*)aligned_alloc(32, len2 * 2 * element_size);

    if (!v0 || !v1 || !v2 || !v3 || !w) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    for (int j = 0; j < len2 * 2; j++) {
        v0[j] = (double)(j % 100) * 0.1;
        v1[j] = (double)(j % 101) * 0.11;
        v2[j] = (double)(j % 102) * 0.12;
        v3[j] = (double)(j % 103) * 0.13;
        w[j]  = (double)(j % 104) * 0.14;
    }

    i = 0;
    sum00 = 0.0;
    sum10 = 0.0;
    sum20 = 0.0;
    sum30 = 0.0;
    sum01 = 0.0;
    sum11 = 0.0;
    sum21 = 0.0;
    sum31 = 0.0;
    w_val0 = 0.0;
    w_val1 = 0.0;
}