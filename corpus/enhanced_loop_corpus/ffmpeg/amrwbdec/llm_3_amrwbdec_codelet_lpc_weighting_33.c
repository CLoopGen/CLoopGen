#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float *out;
extern  float *lpc;
extern float gamma;
extern int size;
extern int i;
extern float fac;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Reverse consecutive memory access
    // Iterates from the last element to the first
    for (i = size - 1; i >= 0; i--) {
        out[i] = lpc[i] * fac;
        fac *= gamma;
    }
}
