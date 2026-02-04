#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <inttypes.h>

float *su1;
float *su2;
int band;
int nsample;
float w[2][2];

void init_vars() {
    const size_t total_size = 1024 * 1024 * 4; // ~4MB of data to ensure sufficient runtime
    
    su1 = (float*)aligned_alloc(32, total_size * sizeof(float));
    su2 = (float*)aligned_alloc(32, total_size * sizeof(float));
    
    if (!su1 || !su2) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }
    
    for (size_t i = 0; i < total_size; i++) {
        su1[i] = 1.0f + (i % 100) * 0.01f;
        su2[i] = 1.5f + (i % 100) * 0.01f;
    }
    
    w[0][0] = 0.8f;
    w[0][1] = 1.2f;
    w[1][0] = 0.9f;
    w[1][1] = 1.1f;
}