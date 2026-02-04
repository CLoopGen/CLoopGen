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
    // Variant 2: Consecutive forward access by reindexing base pointer to create dense pattern
    float *base = diff_isf + 7;
    for (i = 0; i < (16 - 2 - 7); i++) {
        float prod = (base[i] - mean) * (base[i - lag] - mean);
        sum += prod * prod;
    }
}
