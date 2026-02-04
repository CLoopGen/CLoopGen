#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float **h;
extern int *len;
extern float phase;
extern float *work;
extern int i;
extern int work_len;
extern int begin;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access with stride of 2 (forward and backward based on condition)
    int stride = 2;
    int j = 0;
    for (i = 0; i < *len; i += stride) {
        int index = begin + (phase > 50.F ? *len - 1 - i : i);
        (*h)[j] = work[(index + work_len) & (work_len - 1)];
        j++;
        if (j >= *len) break;
    }
    // Fill remaining elements if stride caused underfill
    for (; j < *len; j++) {
        int index = begin + (phase > 50.F ? *len - 1 - j : j);
        (*h)[j] = work[(index + work_len) & (work_len - 1)];
    }
}
