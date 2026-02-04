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
    // Variant 1: Strided memory access with stride of 2
    for (i = 0; i < len; i += 2) {
        w[i] += a0 * v0[i] + a1 * v1[i] + a2 * v2[i] + a3 * v3[i];
        if (i + 1 < len) {
            w[i+1] += a0 * v0[i+1] + a1 * v1[i+1] + a2 * v2[i+1] + a3 * v3[i+1];
        }
    }
}
