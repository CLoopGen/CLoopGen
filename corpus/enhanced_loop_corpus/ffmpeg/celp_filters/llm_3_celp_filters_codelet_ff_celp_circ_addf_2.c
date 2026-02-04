#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float *out;
extern  float *in;
extern  float *lagged;
extern int lag;
extern float fac;
extern int n;
extern int k;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Consecutive forward access with array base offset adjustment
    // Ensures consecutive access by shifting the iteration origin and accessing elements in order
    float *in_offset = in + lag;
    float *lagged_offset = lagged;
    float *out_offset = out + lag;
    int start = lag;
    for (int k = start; k < n; k++) {
        out_offset[k - start] = in_offset[k - start] + fac * lagged_offset[k - start];
    }
}
