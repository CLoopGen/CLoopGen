#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  float synthesis_high[9];
extern float *output;
extern float *temp;
extern int i;
extern int findex;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access by reordering computations to access output array in increasing order
    // Instead of scattering writes with strided access, we reorganize the loop to write to consecutive output indices
    for (i = 8; i < findex + 11; i++) {
        const float t = temp[i];
        const float a = t * synthesis_high[0];
        const float b = t * synthesis_high[1];
        const float c = t * synthesis_high[2];
        const float d = t * synthesis_high[3];
        const float e = t * synthesis_high[4];

        // Compute base index to reduce repeated arithmetic
        const int base = 2 * i - 13;

        // Write to output in increasing order of memory address
        output[base + 0] += a;
        output[base + 1] += b;
        output[base + 2] += c;
        output[base + 3] += d;
        output[base + 4] += e;
        output[base + 5] += d;
        output[base + 6] += c;
        output[base + 7] += b;
        output[base + 8] += a;
    }
}
