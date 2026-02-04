#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float *bandE;
extern float sum[22];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    float prev = 0.0f;
    for (int i = 0; i < 22; i++) {
        bandE[i] = sum[i] + prev;
        prev = sum[i];
    }
}
