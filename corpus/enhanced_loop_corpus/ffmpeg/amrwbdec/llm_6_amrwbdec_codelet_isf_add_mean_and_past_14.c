#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int16_t isf_mean[16];
extern float *isf_q;
extern float *isf_past;
extern int i;
extern float tmp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    float temp_store[16];
    for (i = 0; i < 16; i++) {
        temp_store[i] = isf_q[i];
        isf_q[i] += isf_mean[i] * (1.F / (1 << 15));
    }
    for (i = 0; i < 16; i++) {
        isf_q[i] += (1. / 3.) * isf_past[i];
        isf_past[i] = temp_store[i];
    }
}
