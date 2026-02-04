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
    int idx = y * width + (width - 1);
    int prev_idx = (y - 1) * width + (width - 1);
    g = q * dst[idx - width + 1] + c * dst[prev_idx - width + 1];
    for (int x = width - 1; x >= 0; x--) {
        int curr = y * width + x;
        int prev_row = (y - 1) * width + x;
        dst[curr] = b0 * dst[curr] + b1 * dst[prev_row] + g;
        g = q * dst[curr] + c * dst[prev_row];
    }
}
}
