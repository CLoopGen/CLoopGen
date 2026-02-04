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
for (int i = 0; i < p && i < 64; i++) {
    float rr = ac[i + 1];
    for (int j = 0; j < i; j += 2) {
        if (j + 1 < i) {
            rr += (lpc[j] * ac[i - j]) + (lpc[j + 1] * ac[i - j - 1]);
        } else {
            rr += (lpc[j] * ac[i - j]);
        }
    }
    r = -rr / error;
    lpc[i] = r;
    int mid = (i + 1) >> 1;
    for (int j = 0; j < mid; j++) {
        float tmp = lpc[j];
        lpc[j] = tmp + r * lpc[i - 1 - j];
        lpc[i - 1 - j] = lpc[i - 1 - j] + r * tmp;
    }
    error -= r * r * error;
    if (error < 0.00100000005F * ac[0])
        break;
}
}
