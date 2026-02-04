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
        float val = x_lp[2 * j];
        if (val >= 0.0f) {
            x_lp4[j] = val * 1.1f;
        } else {
            x_lp4[j] = val * 0.9f;
        }
    }
}
