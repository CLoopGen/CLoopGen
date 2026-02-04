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
    float temp = 0.0f;
    for (i = 0; i < 16 - 1; i++) {
        float diff = isf[i] - isf_past[i];
        temp += diff * diff;
    }
    acc += temp;
}
