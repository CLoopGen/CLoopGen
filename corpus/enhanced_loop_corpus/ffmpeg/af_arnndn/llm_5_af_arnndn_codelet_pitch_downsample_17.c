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
        float temp_left  = x[0][(2 * i - 1)];
        float temp_right = x[0][(2 * i + 1)];
        float temp_mid   = x[0][2 * i];

        if (temp_left >= temp_mid || temp_right >= temp_mid) {
            x_lp[i] = 0.5F * (0.5F * (temp_left + temp_right) + temp_mid);
        } else {
            x_lp[i] = temp_mid;
        }
    }
}
