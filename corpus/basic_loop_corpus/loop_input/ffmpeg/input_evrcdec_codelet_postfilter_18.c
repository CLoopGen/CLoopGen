#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <math.h>

#define DATA_SIZE_MB 64
#define TOTAL_ELEMENTS (DATA_SIZE_MB * (1 << 20) / sizeof(float))

float *in;
int length;
float scratch[54];
float sum1;
float sum2;
int i;

void init_vars() {
    length = (TOTAL_ELEMENTS < 54) ? TOTAL_ELEMENTS : 54;
    
    in = (float*)aligned_alloc(32, length * sizeof(float));
    if (!in) {
        length = 54;
        in = (float*)aligned_alloc(32, length * sizeof(float));
    }
    
    for (int idx = 0; idx < length; idx++) {
        in[idx] = 1.0f + idx * 0.1f;
        scratch[idx] = 2.0f + idx * 0.2f;
    }
    
    sum1 = 0.0f;
    sum2 = 0.0f;
    i = 0;
}