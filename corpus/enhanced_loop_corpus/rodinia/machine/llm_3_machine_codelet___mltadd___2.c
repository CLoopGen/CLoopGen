#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern double *dp1;
extern double *dp2;
extern double s;
extern int i;
extern int len4;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided access with increased stride (less dense, larger step)
    // Access every 8th element starting from offset 0, 1, 2, 3 within each block of 8
    // Simulates a more scattered memory access pattern, possibly modeling sparse data
    int stride = 8;
    int total_len = len4 * 4;
    for (i = 0; i < total_len; i++) {
        int idx = (i / 4) * stride + (i % 4); // Map linear index to strided position
        dp1[idx] += s * dp2[idx];
    }
}
