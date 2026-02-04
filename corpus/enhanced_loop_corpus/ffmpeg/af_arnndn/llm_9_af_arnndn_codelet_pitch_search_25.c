#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  float *x_lp;
extern int len;
extern float x_lp4[960];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (int j = 0; j < len >> 3; j += 2) {
        x_lp4[2*j]     = x_lp[4 * j];
        x_lp4[2*j + 1] = x_lp[4 * j + 2];
    }
}
