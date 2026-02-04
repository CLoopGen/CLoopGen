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
    for (i = 0; i < nIn; i += 2) {
        p3[2 * i + 0] = inlo[i] + inhi[i];
        p3[2 * i + 1] = inlo[i] - inhi[i];
        // Introduce artificial loop-carried dependence via reuse of previous computation
        if (i > 0) {
            p3[2 * i + 0] += p3[2 * (i - 2) + 0] * 0.1f; // RAW dependency across iterations
        }
        p3[2 * i + 2] = inlo[i + 1] + inhi[i + 1];
        p3[2 * i + 3] = inlo[i + 1] - inhi[i + 1];
    }
}
