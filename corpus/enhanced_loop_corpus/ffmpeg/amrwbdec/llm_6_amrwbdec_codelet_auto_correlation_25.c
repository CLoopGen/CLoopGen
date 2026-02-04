#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float *diff_isf;
extern float mean;
extern int lag;
extern int i;
extern float sum;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    float temp_sum = 0.0f;
    for (i = 7; i < 14; i++) {
        float diff1 = diff_isf[i] - mean;
        float diff2 = diff_isf[i - lag] - mean;
        float prod = diff1 * diff2;
        temp_sum += prod * prod;
    }
    sum += temp_sum;
}
