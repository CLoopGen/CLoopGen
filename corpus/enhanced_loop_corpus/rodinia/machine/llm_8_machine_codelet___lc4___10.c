#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern double *v0;
extern double *v1;
extern double *v2;
extern double *v3;
extern double *w;
extern int len;
extern int i;
extern double a0;
extern double a1;
extern double a2;
extern double a3;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Increased computational intensity with unrolled loop (4x unrolling) and additional arithmetic operations
    int i;
    for (i = 0; i < len - 3; i += 4) {
        w[i]   += a0 * v0[i]   + a1 * v1[i]   + a2 * v2[i]   + a3 * v3[i]   + (a0 + a1) * (v0[i] + v1[i]);
        w[i+1] += a0 * v0[i+1] + a1 * v1[i+1] + a2 * v2[i+1] + a3 * v3[i+1] + (a2 + a3) * (v2[i+1] + v3[i+1]);
        w[i+2] += a0 * v0[i+2] + a1 * v1[i+2] + a2 * v2[i+2] + a3 * v3[i+2] + (a0 + a2) * (v0[i+2] + v2[i+2]);
        w[i+3] += a0 * v0[i+3] + a1 * v1[i+3] + a2 * v2[i+3] + a3 * v3[i+3] + (a1 + a3) * (v1[i+3] + v3[i+3]);
    }
    // Handle remaining elements
    for (; i < len; i++) {
        w[i] += a0 * v0[i] + a1 * v1[i] + a2 * v2[i] + a3 * v3[i];
    }
}
