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
    for (int j = 0; j < i; j++)
        rr += (lpc[j] * ac[i - j]);
    rr += ac[i + 1];
    r = -rr / error;
    lpc[i] = r;
    for (int j = 0; j < (i + 1) >> 1; j++) {
        float tmp1, tmp2;
        tmp1 = lpc[j];
        tmp2 = lpc[i - 1 - j];
        lpc[j] = tmp1 + (r * tmp2);
        lpc[i - 1 - j] = tmp2 + (r * tmp1);
    }
    error = error - (r * r * error);
}
}
