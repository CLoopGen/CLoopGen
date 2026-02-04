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
for (i = 0; i < 32; i += 2) {
    int idx = i >> 1;
    tmp = isf_q[idx];
    isf_q[idx] += isf_mean[idx] * (1.F / (1 << 15));
    isf_q[idx] += (1. / 3.) * isf_past[idx];
    isf_past[idx] = tmp;
    isf_q[idx] += (0.5F / 7) * (isf_q[idx] - isf_past[idx]);
}
}
