#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float *inlo;
extern float *inhi;
extern unsigned int nIn;
extern int i;
extern float *p3;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access with loop unrolling and stride-1 access pattern
    // Reorganize computation to access p3, inlo, and inhi in a more sequential (cache-friendly) manner
    float *p = p3;
    for (i = 0; i < nIn; i += 2) {
        float lo0 = inlo[i];
        float hi0 = inhi[i];
        float lo1 = inlo[i + 1];
        float hi1 = inhi[i + 1];

        *p++ = lo0 + hi0;
        *p++ = lo0 - hi0;
        *p++ = lo1 + hi1;
        *p++ = lo1 - hi1;
    }
}
