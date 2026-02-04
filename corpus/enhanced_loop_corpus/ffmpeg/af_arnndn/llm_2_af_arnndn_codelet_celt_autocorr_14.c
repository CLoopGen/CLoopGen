#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  float *x;
extern  float *window;
extern int overlap;
extern int n;
extern float xx[864];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access with pointer arithmetic
    float *xp = x;
    float *wp = window;
    float *xxp = xx;
    float *x_end = x + overlap;
    
    for (int i = 0; i < overlap; i++) {
        xxp[i] = xp[i] * wp[i];
        xxp[n - i - 1] = xp[n - i - 1] * wp[i];
    }
}
