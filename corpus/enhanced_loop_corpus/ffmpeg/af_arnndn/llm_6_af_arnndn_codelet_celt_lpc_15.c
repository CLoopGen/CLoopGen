#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float *lpc;
extern  float *ac;
extern int p;
extern float r;
extern float error;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (int i = 0; i < p; i++) {
    float rr = ac[i + 1];
    for (int j = 0; j < i; j++)
        rr += (lpc[j] * ac[i - j]);
    float r_local = -rr / error;
    lpc[i] = r_local;
    int mid = (i + 1) >> 1;
    for (int j = 0; j < mid; j++) {
        float tmp1 = lpc[j];
        float tmp2 = lpc[i - 1 - j];
        lpc[j] = tmp1 + (r_local * tmp2);
        lpc[i - 1 - j] = tmp2 + (r_local * tmp1);
    }
    error -= r_local * r_local * error;
    if (error < 0.00100000005F * ac[0])
        break;
}
}
