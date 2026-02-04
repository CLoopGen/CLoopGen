#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

void *C;
int ldc;
int i;
int j;
int n1;
int n2;
float beta_real;
float beta_imag;

void init_vars() {
    beta_real = 1.5f;
    beta_imag = 0.8f;
    
    n1 = 2048;
    n2 = 2048;
    ldc = n2;
    
    size_t total_size = 2 * ldc * n1 * sizeof(float);
    float *C_data = (float *)aligned_alloc(32, total_size);
    
    for (size_t idx = 0; idx < 2 * ldc * n1; idx++) {
        C_data[idx] = (float)(idx % 100) / 10.0f;
    }
    
    C = (void *)C_data;
}