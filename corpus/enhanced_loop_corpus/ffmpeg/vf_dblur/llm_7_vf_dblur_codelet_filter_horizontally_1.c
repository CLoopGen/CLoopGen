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
    float prev_g = 0.0f;
    for (int y = height - 2; y >= 0; y--) {
        float local_g = q * dst[y * width + (width - 1)] + c * dst[y * width + (width - 1)];
        for (int x = width - 1; x >= 0; x--) {
            int curr_idx = y * width + x;
            int next_y_idx = (y + 1) * width + x;
            float old_dst = dst[curr_idx];
            dst[curr_idx] += b1 * dst[next_y_idx] + local_g - dst[curr_idx] + b0 * dst[curr_idx];
            local_g = q * old_dst + c * dst[next_y_idx];
        }
        prev_g = local_g;
    }
    g = prev_g;
}
