#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float *data;
extern int period;
extern int len;
extern  float g0;
extern  float g1;
extern  float g2;
extern float x4;
extern float x3;
extern float x2;
extern float x1;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    const int unroll_factor = 4;
    int i = 0;
    for (; i <= len - unroll_factor; i += unroll_factor) {
        float x0_vals[unroll_factor];
        for (int j = 0; j < unroll_factor; ++j) {
            x0_vals[j] = data[i + j - period + 2];
        }

        data[i]   += g0 * x2 + g1 * (x1 + x3) + g2 * (x0_vals[0] + x4);
        data[i+1] += g0 * x1 + g1 * (x4 + x2) + g2 * (x0_vals[1] + x3);
        data[i+2] += g0 * x4 + g1 * (x3 + x1) + g2 * (x0_vals[2] + x2);
        data[i+3] += g0 * x3 + g1 * (x2 + x4) + g2 * (x0_vals[3] + x1);

        x1 = x0_vals[0];
        x2 = x0_vals[1];
        x3 = x0_vals[2];
        x4 = x0_vals[3];
    }

    for (; i < len; ++i) {
        float x0 = data[i - period + 2];
        data[i] += g0 * x2 + g1 * (x1 + x3) + g2 * (x0 + x4);
        x4 = x3;
        x3 = x2;
        x2 = x1;
        x1 = x0;
    }
}
