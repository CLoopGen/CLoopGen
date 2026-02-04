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
    float temp = dst[0];
    g = q * temp + c * temp;
    for (int x = 0; x < width; x++) {
        int idx = y * width + x;
        int prev_idx = (y - 1) * width + x;
        float new_val = b0 * dst[idx] + b1 * dst[prev_idx] + g;
        dst[idx] = new_val;
        g = q * new_val + c * dst[prev_idx];
    }
}
}
