#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float diff_isf[14];
extern float diff_mean;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access (access every 2nd element starting from index 2)
    for (i = 2; i < 16 - 2; i += 2)
        diff_mean += diff_isf[i] * (1.F / (16 - 4));
}
