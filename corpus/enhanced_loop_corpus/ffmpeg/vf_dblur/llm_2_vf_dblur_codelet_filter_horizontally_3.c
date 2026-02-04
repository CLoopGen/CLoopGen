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
for (int y = height - 2; y >= 0; y--) {
    int base_idx = y * width;
    int next_base_idx = (y + 1) * width;
    g = q * dst[base_idx] + c * dst[base_idx];
    for (int x = 0; x < width; x++) {
        int idx = base_idx + x;
        int next_idx = next_base_idx + x;
        dst[idx] = b0 * dst[idx] + b1 * dst[next_idx] + g;
        g = q * dst[idx] + c * dst[next_idx];
    }
}
}
