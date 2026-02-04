#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float *x[];
extern float *x_lp;
extern int len;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (int i = 1; i < len >> 1; i++) {
        if (i % 2 == 0) {
            x_lp[i] = 0.5F * (0.5F * (x[0][(2 * i - 1)] + x[0][(2 * i + 1)]) + x[0][2 * i]);
        } else {
            x_lp[i] = x[0][2 * i];
        }
    }
}
