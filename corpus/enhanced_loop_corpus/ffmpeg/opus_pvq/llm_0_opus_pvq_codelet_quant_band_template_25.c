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
    uint32_t j;
    for (j = 0; j < N0; j++) {
        for (i = j; i < j + 1 && i < N0; i++)
            lowband_out[i] = n * X[i];
    }
}
