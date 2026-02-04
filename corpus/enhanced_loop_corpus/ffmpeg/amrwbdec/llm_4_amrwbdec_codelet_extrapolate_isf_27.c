#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float diff_isf[14];
extern float diff_mean;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    float factor = 1.F / (16 - 4);
    for (i = 2; i < 14; i++) {
        if (diff_isf[i] > 0.0f) {
            diff_mean += diff_isf[i] * factor;
        }
    }
}
