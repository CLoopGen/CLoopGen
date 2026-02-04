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
float prev_error = error;
for (int i = 0; i < p; i++) {
    float rr = 0;
    for (int j = 0; j <= i/2; j++) {
        if (j < i)
            rr += (lpc[j] * ac[i - j]);
    }
    rr += ac[i + 1];
    float r_local = -rr / prev_error;
    lpc[i] = r_local;
    for (int j = 0; j < (i + 1) >> 1; j++) {
        float tmp1 = lpc[j] + (r_local * lpc[i - 1 - j]);
        float tmp2 = lpc[i - 1 - j] + (r_local * lpc[j]);
        lpc[j] = tmp1;
        lpc[i - 1 - j] = tmp2;
    }
    prev_error = prev_error - (r_local * r_local * prev_error);
    if (prev_error < 0.00100000005F * ac[0]) {
        error = prev_error;
        break;
    }
    if (i == p - 1)
        error = prev_error;
}
}
