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
    float temp_g = q * dst[y * width + (width - 1)] + c * dst[(y - 1) * width + (width - 1)];
    for (int x = width - 1; x >= 0; x--) {
        int idx_curr = y * width + x;
        int idx_prev = (y - 1) * width + x;
        dst[idx_curr] = b0 * dst[idx_curr] + b1 * dst[idx_prev] + temp_g;
        temp_g = q * dst[idx_curr] + c * dst[idx_prev];
    }
}
}
