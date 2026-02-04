#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float *bandE;
extern float sum[22];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (int i = 0; i < 22; ++i) {
        if (!(sum[i] < 0.0f)) {
            bandE[i] = sum[i];
        } else {
            bandE[i] = 0.0f;
        }
    }
}
