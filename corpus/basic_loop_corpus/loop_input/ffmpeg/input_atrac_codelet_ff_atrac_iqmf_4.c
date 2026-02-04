#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <time.h>
#include <stdint.h>

float *inlo;
float *inhi;
unsigned int nIn;
int i;
float *p3;

void init_vars() {
    const size_t data_size = 64 * 1024 * 1024; 
    nIn = data_size / sizeof(float);
    
    if (nIn % 2 != 0) nIn--;

    inlo = (float*)aligned_alloc(32, nIn * sizeof(float));
    inhi = (float*)aligned_alloc(32, nIn * sizeof(float));
    p3   = (float*)aligned_alloc(32, (2 * nIn + 4) * sizeof(float));

    for (unsigned int j = 0; j < nIn; j++) {
        inlo[j] = (float)(rand() % 1000) / 10.0f;
        inhi[j] = (float)(rand() % 1000) / 10.0f;
    }

    for (unsigned int j = 0; j < 2 * nIn + 4; j++) {
        p3[j] = 0.0f;
    }
}