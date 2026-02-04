#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float diff_isf[14];
extern float diff_mean;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    float inv_denom = 1.F / (16 - 4);
    for (i = 2; i < 16 - 2; i++) {
        diff_mean += diff_isf[i] * inv_denom;
        diff_mean += diff_isf[i+1] * inv_denom;
        diff_mean += diff_isf[i] * inv_denom * 0.5F;
    }
}
