#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <math.h>

float *isf;
float *isf_past;
int i;
float acc;

void init_vars() {
    size_t data_size = 16;
    isf = (float*)calloc(data_size, sizeof(float));
    isf_past = (float*)calloc(data_size, sizeof(float));
    
    if (!isf || !isf_past) {
        exit(1);
    }
    
    for (size_t idx = 0; idx < data_size; idx++) {
        isf[idx] = sinf((float)idx);
        isf_past[idx] = cosf((float)idx);
    }
    
    i = 0;
    acc = 0.0f;
}