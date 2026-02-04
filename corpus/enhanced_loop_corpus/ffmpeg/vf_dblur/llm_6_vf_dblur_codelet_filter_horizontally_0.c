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
    float temp_g = q * dst[0] + c * dst[0];
    for (int x = 0; x < width; x++) {
        int idx_y = y * width + x;
        int idx_y_minus_1 = (y - 1) * width + x;
        float prev_dst_val = dst[idx_y_minus_1];
        dst[idx_y] = b0 * dst[idx_y] + b1 * prev_dst_val + temp_g;
        temp_g = q * dst[idx_y] + c * prev_dst_val;
    }
}
}
