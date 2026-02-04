#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float *x[];
extern float *x_lp;
extern int len;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    float *x_curr = x_lp;
    float *x_src = x[1];
    int upper = len >> 1;

    if (upper > 1) {
        x_curr[1] += 0.5F * (0.5F * (x_src[1] + x_src[3]) + x_src[2]);
    }

    for (int i = 2; i < upper; i++) {
        float left  = x_src[2 * i - 1];
        float right = x_src[2 * i + 1];
        float mid   = x_src[2 * i];
        float avg   = 0.5F * ((left + right) * 0.5F + mid);
        x_curr[i] += avg;
    }
}
