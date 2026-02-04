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
    float* dst_curr = &dst[y * width];
    float* dst_prev = &dst[(y - 1) * width];
    g = q * dst_curr[width - 1] + c * dst_prev[width - 1];
    for (int x = width - 1; x >= 0; x--) {
        dst_curr[x] = b0 * dst_curr[x] + b1 * dst_prev[x] + g;
        g = q * dst_curr[x] + c * dst_prev[x];
    }
}
}
