#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float *x[];
extern float *x_lp;
extern int len;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    float *x_local = x_lp;
    const float coef = 0.5F;
    int limit = len >> 1;

    for (int i = 1; i < limit; i++) {
        float temp1 = x[1][2 * i - 1] + x[1][2 * i + 1];
        float temp2 = 0.5F * temp1;
        x_local[i] += coef * (temp2 + x[1][2 * i]);
    }
}
