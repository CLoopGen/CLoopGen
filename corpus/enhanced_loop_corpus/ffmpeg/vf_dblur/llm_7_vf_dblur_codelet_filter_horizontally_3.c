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
        float prev_g = q * dst[y * width] + c * dst[y * width];
        float g_local = prev_g;
        for (int x = 0; x < width; x++) {
            int curr_idx = y * width + x;
            int next_idx = (y + 1) * width + x;
            float updated_val = b0 * dst[curr_idx] + b1 * dst[next_idx] + g_local;
            g_local = q * updated_val + c * dst[next_idx];
            dst[curr_idx] = updated_val;
        }
    }
}
