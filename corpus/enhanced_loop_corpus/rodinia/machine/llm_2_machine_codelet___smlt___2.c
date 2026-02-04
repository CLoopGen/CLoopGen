#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern double *dp;
extern double *out;
extern double s;
extern int len;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access with stride of 2
    // Processes every second element in two passes to cover all elements
    int stride = 2;
    int remainder = len % stride;

    for (i = 0; i < len - remainder; i += stride)
        out[i] = s * dp[i];

    // Handle remaining elements if length is not divisible by stride
    for (; i < len; i++)
        out[i] = s * dp[i];
}
