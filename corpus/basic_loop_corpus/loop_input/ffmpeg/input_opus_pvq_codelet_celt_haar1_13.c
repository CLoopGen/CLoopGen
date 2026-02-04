#include <stdlib.h>
#include <stdio.h>

float *X;
int N0;
int stride;
int i;
int j;

void init_vars() {
    stride = 1024;
    N0 = 65536 / stride; // Ensures total data size is about 256KB to 512KB range for reasonable timing (~0.01 sec estimate)
    
    if (N0 == 0) N0 = 1;
    
    size_t total_size = stride * (2 * N0);
    X = (float*)aligned_alloc(32, total_size * sizeof(float));
    
    if (!X) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }
    
    for (size_t idx = 0; idx < total_size; ++idx) {
        X[idx] = (float)(idx % 100) * 0.5f;
    }
}