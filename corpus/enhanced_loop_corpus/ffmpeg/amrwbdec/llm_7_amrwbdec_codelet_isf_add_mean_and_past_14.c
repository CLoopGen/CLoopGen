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
    float prev_tmp;
    tmp = isf_q[0];
    isf_q[0] += isf_mean[0] * (1.F / (1 << 15)) + (1. / 3.) * isf_past[0];
    isf_past[0] = tmp;
    for (i = 1; i < 16; i++) {
        prev_tmp = isf_q[i];
        isf_q[i] += isf_mean[i] * (1.F / (1 << 15)) + (1. / 3.) * isf_past[i];
        isf_past[i] = isf_q[i-1] - isf_mean[i-1] * (1.F / (1 << 15)) - (1. / 3.) * isf_past[i-1]; 
    }
}
