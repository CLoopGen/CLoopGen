#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float *coeff;
extern  float *inbuf;
extern float gamma;
extern double fac;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access with stride of 2 (access every second element)
    // We double the upper bound to ensure we still process up to 10 logical elements
    for (i = 0; i < 20; i += 2) {
        if (i/2 < 10) {
            coeff[i/2] = inbuf[i] * fac;
            fac *= gamma;
        }
    }
}
