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
    float temp;
    for (i = 0; i < N0; i++) {
        temp = n * X[i];
        lowband_out[i] = temp;
    }
}
