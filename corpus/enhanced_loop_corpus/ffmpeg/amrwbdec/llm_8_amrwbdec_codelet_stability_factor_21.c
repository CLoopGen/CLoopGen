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
    for (i = 0; i < 32; i += 2) {
        float diff1 = isf[i] - isf_past[i];
        float diff2 = isf[i+1] - isf_past[i+1];
        acc += diff1 * diff1 + diff2 * diff2;
    }
}
