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
for (int i = 0; i < p && error >= 0.00100000005F * ac[0]; i++) {
    float rr = 0;
    for (int j = 0; j < i; j++)
        rr += (lpc[j] * ac[i - j]);
    rr += ac[i + 1];
    r = -rr / error;
    lpc[i] = r;
    int mid = (i + 1) >> 1;
    for (int j = 0; j < mid; j++) {
        float tmp1 = lpc[j];
        float tmp2 = lpc[i - 1 - j];
        lpc[j] = tmp1 + (r * tmp2);
        lpc[i - 1 - j] = tmp2 + (r * tmp1);
    }
    error -= r * r * error;
}
}
