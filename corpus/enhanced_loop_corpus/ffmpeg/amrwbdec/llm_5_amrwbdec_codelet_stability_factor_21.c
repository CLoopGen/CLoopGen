#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  float *isf;
extern  float *isf_past;
extern int i;
extern float acc;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < 15; ++i) {
        float diff = isf[i] - isf_past[i];
        acc += diff * diff;
        if (acc > 1e6) break;
    }
}
