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
    int center_offset = y * width;
    int prev_offset = (y - 1) * width;
    float *dst_center = &dst[center_offset];
    float *dst_prev = &dst[prev_offset];
    float *dst_base = &dst[0];
    g = q * dst_base[0] + c * dst_base[0];
    for (int x = 0; x < width; x += 2) {
        if (x + 1 < width) {
            g = q * dst_center[x] + c * dst_prev[x];
            dst_center[x] = b0 * dst_center[x] + b1 * dst_prev[x] + g;
            dst_center[x+1] = b0 * dst_center[x+1] + b1 * dst_prev[x+1] + g;
            g = q * dst_center[x+1] + c * dst_prev[x+1];
        } else {
            dst_center[x] = b0 * dst_center[x] + b1 * dst_prev[x] + g;
            g = q * dst_center[x] + c * dst_prev[x];
        }
    }
}
}
