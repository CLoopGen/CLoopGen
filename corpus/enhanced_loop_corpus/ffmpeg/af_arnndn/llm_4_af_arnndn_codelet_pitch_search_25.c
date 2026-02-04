#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  float *x_lp;
extern int len;
extern float x_lp4[960];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (int j = 0; j < (len >> 2); j++) {
        if ((j & 1) == 0) {
            x_lp4[j] = x_lp[2 * j];
        } else {
            x_lp4[j] = 0.0f;
        }
    }
}
