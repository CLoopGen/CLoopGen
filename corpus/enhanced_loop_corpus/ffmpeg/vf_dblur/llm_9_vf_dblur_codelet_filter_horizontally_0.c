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
for (int y = 1; y < height - 1; y += 2) {
    int base_idx = y * width;
    int prev_idx = (y - 1) * width;
    g = q * dst[base_idx] + c * dst[prev_idx];
    for (int x = 0; x < width; x++) {
        float curr = dst[base_idx + x];
        float prev = dst[prev_idx + x];
        dst[base_idx + x] = b0 * curr + b1 * prev + g;
        g = q * curr + c * prev;
        if (x > 0) {
            dst[base_idx + x] += 0.2f * dst[base_idx + x - 1];
        }
    }
}
}
