#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float exponent_tab[50];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access with precomputed indices and unrolled pattern
    float *tab = exponent_tab;
    for (i = 0; i < 25; i++) {
        int shift = 1 << i;
        tab[0] = 1.F / shift;
        tab[1] = 0.70710678118654757F / shift;
        tab += 2; // Move pointer consecutively forward
    }
}
