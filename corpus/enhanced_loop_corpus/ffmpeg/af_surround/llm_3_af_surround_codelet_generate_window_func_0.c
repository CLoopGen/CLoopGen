#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float *lut;
extern int N;
extern int n;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Reverse consecutive memory access
    for (n = N - 1; n >= 0; n--)
        lut[n] = 1.;
}
