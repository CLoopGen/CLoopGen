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
        float temp_g = q * dst[y * width] + c * dst[y * width];
        for (int x = 0; x < width; x++) {
            int idx = y * width + x;
            int idx_up = (y + 1) * width + x;
            float new_val = b0 * dst[idx] + b1 * dst[idx_up] + temp_g;
            temp_g = q * new_val + c * dst[idx_up];
            dst[idx] = new_val;
        }
    }
}
