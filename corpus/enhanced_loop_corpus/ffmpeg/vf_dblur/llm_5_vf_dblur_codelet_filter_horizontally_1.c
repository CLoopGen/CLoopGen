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
        g = q * dst[y * width + (width - 1)] + c * dst[y * width + (width - 1)];
        for (int x = width - 1; x >= 0; x--) {
            float temp_val = dst[y * width + x];
            float neighbor_val = dst[(y + 1) * width + x];
            if (temp_val > 0.0f && neighbor_val < 1.0f) {
                dst[y * width + x] = b0 * temp_val + b1 * neighbor_val + g;
            } else {
                dst[y * width + x] = b0 * temp_val + b1 * neighbor_val;
            }
            g = q * dst[y * width + x] + c * neighbor_val;
        }
    }
}
