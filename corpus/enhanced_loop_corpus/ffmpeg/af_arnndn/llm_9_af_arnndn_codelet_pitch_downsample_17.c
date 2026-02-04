#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float *x[];
extern float *x_lp;
extern int len;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (int i = 1; i < (len >> 2); i++) {
        float val1 = x[0][(4 * i - 1)];
        float val2 = x[0][(4 * i + 1)];
        float val3 = x[0][4 * i];
        x_lp[2*i]   = 0.5F * (0.5F * (val1 + val2) + val3);
        x_lp[2*i-1] = 0.25F * (val1 + val3);
    }
}
