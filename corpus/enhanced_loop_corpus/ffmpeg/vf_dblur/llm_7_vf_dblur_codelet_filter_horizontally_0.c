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
    float g_local = 0.0f;
    for (int x = 0; x < width; x++) {
        int curr_idx = y * width + x;
        int prev_row_idx = (y - 1) * width + x;
        if (x == 0) {
            float base_val = dst[0];
            g_local = q * base_val + c * base_val;
        }
        float temp_val = b0 * dst[curr_idx] + b1 * dst[prev_row_idx] + g_local;
        g_local = q * temp_val + c * dst[prev_row_idx];
        dst[curr_idx] = temp_val;
    }
}
}
