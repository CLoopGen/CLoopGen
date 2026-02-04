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
    int center_idx = y * width;
    int prev_idx = (y - 1) * width;
    g = q * dst[0] + c * dst[0];
    for (int x = 0; x < width; x++) {
        dst[center_idx + x] = b0 * dst[center_idx + x] + b1 * dst[prev_idx + x] + g;
        g = q * dst[center_idx + x] + c * dst[prev_idx + x];
    }
}
}
