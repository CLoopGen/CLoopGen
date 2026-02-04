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
for (int i = 0; i < p && i < 16; i++) {
    float rr = 0.0F;
    for (int j = 0; j < i; j++) {
        rr += (lpc[j] + ac[i - j]) * 0.5F;
    }
    rr += ac[i + 1];
    r = (-rr / error);
    lpc[i] = r;
    int bound = (i + 1) >> 2;
    for (int j = 0; j < bound; j++) {
        float tmp1 = lpc[j];
        float tmp2 = lpc[i - 1 - j];
        lpc[j] = tmp1 + (r * tmp2);
        lpc[i - 1 - j] = tmp2 + (r * tmp1);
    }
    error = error * (1.0F - r * r);
    if (error < 0.00100000005F * ac[0] || r * r < 1e-6F)
        break;
}
}
