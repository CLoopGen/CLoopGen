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
    for (i = 0; i < N0; i += 2) {
        lowband_out[i] = n * X[i];
        if (i + 1 < N0) {
            lowband_out[i + 1] = n * X[i + 1];
        }
    }
}
