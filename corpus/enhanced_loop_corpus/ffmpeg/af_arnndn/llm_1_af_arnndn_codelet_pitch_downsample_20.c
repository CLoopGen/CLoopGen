#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float *x[];
extern float *x_lp;
extern int len;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (int i = 1; i < len >> 2; i++) {
        for (int k = 0; k < 2; k++) {
            int idx = i * 2 + k;
            if (idx < (len >> 1)) {
                x_lp[idx] += (0.5F * (0.5F * (x[1][(2 * idx - 1)] + x[1][(2 * idx + 1)]) + x[1][2 * idx]));
            }
        }
    }
}
