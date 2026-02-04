#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <time.h>
#include <math.h>

#define DATA_SIZE_MB 64

void *B;
int ldb;
int i;
int j;
int n1;
int n2;
float alpha_real;
float alpha_imag;

static float *B_data = NULL;

void init_vars() {
    const size_t total_elements = (DATA_SIZE_MB * (1 << 20)) / sizeof(float);
    B_data = aligned_alloc(32, total_elements * sizeof(float));
    
    if (!B_data) {
        exit(1);
    }

    for (size_t idx = 0; idx < total_elements; ++idx) {
        B_data[idx] = (float)(rand() % 100) / 10.0f;
    }

    alpha_real = 1.5f;
    alpha_imag = 0.8f;

    n1 = sqrt(total_elements / 2) / 2;
    n2 = sqrt(total_elements / 2) / 2;

    ldb = n2 + 10;

    B = B_data;
}