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
    float temp_g = q * dst[y * width + (width - 1)] + c * dst[(y - 1) * width + (width - 1)];
    for (int x = width - 2; x >= 0; x--) {
        float new_val = b0 * dst[y * width + x] + b1 * dst[(y - 1) * width + x] + temp_g;
        temp_g = q * new_val + c * dst[(y - 1) * width + x];
        dst[y * width + x] = new_val;
    }
    // Handle x = width - 1 separately to preserve dependency chain start
    dst[y * width + (width - 1)] = b0 * dst[y * width + (width - 1)] + 
                                  b1 * dst[(y - 1) * width + (width - 1)] + 
                                  q * dst[y * width + (width - 1)] + 
                                  c * dst[(y - 1) * width + (width - 1)];
}
}
