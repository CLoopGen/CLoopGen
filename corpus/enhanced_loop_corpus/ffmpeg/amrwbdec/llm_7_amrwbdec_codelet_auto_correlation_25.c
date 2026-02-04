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
    float local_sum = sum;
    for (i = 7; i < 14; i += 2) {
        float prod1 = (diff_isf[i] - mean) * (diff_isf[i - lag] - mean);
        local_sum += prod1 * prod1;
        if (i + 1 < 14) {
            float prod2 = (diff_isf[i + 1] - mean) * (diff_isf[i + 1 - lag] - mean);
            local_sum += prod2 * prod2;
        }
    }
    sum = local_sum;
}
