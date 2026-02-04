#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  float *x_lp;
extern int len;
extern float x_lp4[960];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (int j = 0; j < len >> 2; j++) {
        float val1 = x_lp[2 * j];
        float val2 = x_lp[2 * j + 1];
        x_lp4[j] = val1 * val2 + val1 - val2;
    }
}
