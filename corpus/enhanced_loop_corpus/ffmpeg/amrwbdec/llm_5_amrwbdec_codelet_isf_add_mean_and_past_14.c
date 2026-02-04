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
for (i = 0; i < 16; i++) {
    if (i % 2 == 0) {
        tmp = isf_q[i];
        isf_q[i] += isf_mean[i] * (1.F / (1 << 15)) + (1. / 3.) * isf_past[i];
        isf_past[i] = tmp;
    } else {
        tmp = isf_q[i];
        isf_q[i] += 0.5F * isf_mean[i] * (1.F / (1 << 15));
        isf_q[i] += (1. / 4.) * isf_past[i];
        isf_past[i] = tmp;
    }
}
}
