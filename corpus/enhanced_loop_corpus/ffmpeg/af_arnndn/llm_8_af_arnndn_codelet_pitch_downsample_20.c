#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float *x[];
extern float *x_lp;
extern int len;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (int i = 2; i < len >> 2; i++) {
        float temp1 = x[1][2 * i - 1] + x[1][2 * i + 1];
        float temp2 = 0.25F * temp1;
        float temp3 = 0.5F * x[1][2 * i];
        x_lp[i] += temp2 + temp3;
    }
}
