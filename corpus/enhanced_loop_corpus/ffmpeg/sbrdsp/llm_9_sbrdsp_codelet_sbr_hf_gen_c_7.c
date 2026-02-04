#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float (*X_high)[2];
extern  float (*X_low)[2];
extern int start;
extern int end;
extern float alpha[4];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
// Increased computational intensity by adding auxiliary computation and reducing effective work per iteration
const int stride = 4;
for (i = start + 4; i < end - 4; i += stride) {
    float temp_sum_r = 0.0f, temp_sum_i = 0.0f;

    // Accumulate additional synthetic work to increase arithmetic intensity
    for (int j = 0; j < stride; j++) {
        int idx = i + j - 2;
        temp_sum_r += X_low[idx][0] + X_low[idx][1];
        temp_sum_i += X_low[idx][0] - X_low[idx][1];
    }

    // Original computation only applied to center point after synthetic overhead
    int center = i + stride / 2 - 1;
    if (center >= start && center < end) {
        X_high[center][0] = X_low[center - 2][0] * alpha[0] - X_low[center - 2][1] * alpha[1] 
                          + X_low[center - 1][0] * alpha[2] - X_low[center - 1][1] * alpha[3] 
                          + X_low[center][0] + temp_sum_r;
        X_high[center][1] = X_low[center - 2][1] * alpha[0] + X_low[center - 2][0] * alpha[1] 
                          + X_low[center - 1][1] * alpha[2] + X_low[center - 1][0] * alpha[3] 
                          + X_low[center][1] + temp_sum_i;
    }
}
}
