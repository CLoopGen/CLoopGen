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
    float rr = 0;
    int j = 0;
    for (; j < i; j++) {
        rr += (lpc[j] * ac[i - j]);
    }
    rr += ac[i + 1];
    r = -rr / error;
    lpc[i] = r;
    int mid = (i + 1) >> 1;
    if (mid > 0) {
        for (int jj = 0; jj < mid; jj++) {
            float tmp1 = lpc[jj];
            float tmp2 = lpc[i - 1 - jj];
            lpc[jj] = tmp1 + (r * tmp2);
            lpc[i - 1 - jj] = tmp2 + (r * tmp1);
        }
    }
    error = error - (r * r * error);
    if (error < 0.00100000005F * ac[0])
        break;
}
}
