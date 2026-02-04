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
    int idx = y * width + (width - 1);
    g = q * dst[idx] + c * dst[idx];
    for (int x = width - 1; x >= 0; x--) {
        int curr_idx = y * width + x;
        int next_y_idx = (y + 1) * width + x;
        dst[curr_idx] = b0 * dst[curr_idx] + b1 * dst[next_y_idx] + g;
        g = q * dst[curr_idx] + c * dst[next_y_idx];
    }
}
}
