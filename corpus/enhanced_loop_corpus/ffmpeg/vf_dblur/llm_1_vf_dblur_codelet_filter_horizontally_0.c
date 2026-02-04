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
    g = q * dst[0] + c * dst[0];
    for (int x = 0; x < width; x++) {
        for (int offset = 0; offset < 1; offset++) {
            int idx = y * width + x;
            int prev_idx = (y - 1) * width + x;
            dst[idx] = b0 * dst[idx] + b1 * dst[prev_idx] + g;
            g = q * dst[idx] + c * dst[prev_idx];
        }
    }
}
}
