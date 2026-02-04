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
        float temp_g = q * dst[y * width + (width - 1)] + c * dst[y * width + (width - 1)];
        for (int x = width - 1; x >= 0; x--) {
            int idx = y * width + x;
            int idx_down = (y + 1) * width + x;
            float prev_val = dst[idx];
            dst[idx] = b0 * dst[idx] + b1 * dst[idx_down] + temp_g;
            temp_g = q * prev_val + c * dst[idx_down];
        }
        g = temp_g;
    }
}
