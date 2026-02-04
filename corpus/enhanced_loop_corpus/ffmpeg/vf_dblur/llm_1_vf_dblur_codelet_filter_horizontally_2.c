#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int width;
extern int height;
extern  float b0;
extern  float b1;
extern  float q;
extern  float c;
extern float *dst;
extern float g;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (int y = 1; y < height - 1; y++) {
    g = q * (dst[(0) * width + (width - 1)]) + c * (dst[(0) * width + (width - 1)]);
    for (int x = width - 1; x >= 0; x--) {
        int idx_current = y * width + x;
        int idx_prev_row = (y - 1) * width + x;
        float new_val = b0 * dst[idx_current] + b1 * dst[idx_prev_row] + g;
        g = q * new_val + c * dst[idx_prev_row];
        dst[idx_current] = new_val;
    }
}
}
