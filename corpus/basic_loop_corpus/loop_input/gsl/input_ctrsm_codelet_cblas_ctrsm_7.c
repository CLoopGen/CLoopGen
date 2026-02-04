#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <time.h>
#include <math.h>

#define DATA_SIZE_MB 64

static float *B_data;
int ldb;
int i;
int j;
int n1;
int n2;
float alpha_real;
float alpha_imag;
void *B;

void init_vars() {
    const size_t total_elements = (DATA_SIZE_MB * (1 << 20)) / sizeof(float);
    B_data = (float*)aligned_alloc(32, total_elements * sizeof(float));
    
    n1 = sqrt(total_elements / 2) / 2;
    n2 = sqrt(total_elements / 2) / 2;
    
    ldb = n2 + 16; 
    
    while ((size_t)(2 * ldb * (n1 - 1) + 2 * (n2 - 1) + 2) >= total_elements) {
        n1--;
        n2--;
    }

    for (size_t idx = 0; idx < total_elements; idx++) {
        B_data[idx] = (float)((idx % 128) - 64);
    }

    B = (void*)B_data;

    alpha_real = 1.5f;
    alpha_imag = 0.8f;

    i = 0;
    j = 0;
}

__attribute__((destructor))
static void cleanup() {
    if (B_data) {
        free(B_data);
    }
}