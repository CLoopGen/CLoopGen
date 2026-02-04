#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  float *x_lp;
extern int len;
extern float x_lp4[960];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    if (len > 0) {
        for (int j = 0; j < (len >> 2); j += 4) {
            x_lp4[j]     = x_lp[2 * j];
            if (j + 1 < (len >> 2)) x_lp4[j + 1] = x_lp[2 * (j + 1)];
            if (j + 2 < (len >> 2)) x_lp4[j + 2] = x_lp[2 * (j + 2)];
            if (j + 3 < (len >> 2)) x_lp4[j + 3] = x_lp[2 * (j + 3)];
        }
    }
}
