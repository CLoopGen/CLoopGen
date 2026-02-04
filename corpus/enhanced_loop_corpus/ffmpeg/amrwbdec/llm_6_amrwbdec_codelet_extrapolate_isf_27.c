#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float diff_isf[14];
extern float diff_mean;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    float temp_sum = 0.0F;
    for (i = 2; i < 14; i++) {
        temp_sum += diff_isf[i];
    }
    diff_mean += temp_sum * (1.F / (16 - 4));
}
