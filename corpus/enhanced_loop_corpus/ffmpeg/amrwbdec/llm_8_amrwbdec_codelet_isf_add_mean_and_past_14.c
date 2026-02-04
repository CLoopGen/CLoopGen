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
for (i = 0; i < 8; i++) {
    tmp = isf_q[i];
    isf_q[i] += isf_mean[i] * (1.F / (1 << 14));
    isf_past[i] = tmp;
}
}
