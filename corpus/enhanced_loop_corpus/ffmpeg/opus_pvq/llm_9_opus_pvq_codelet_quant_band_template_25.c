#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float *X;
extern float *lowband_out;
extern int i;
extern uint32_t N0;
extern float n;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    uint32_t i;
    float n_sq = n * n;
    for (i = 0; i < N0; i++) {
        float x_val = X[i];
        lowband_out[i] = n_sq * x_val + n * x_val;
    }
}
