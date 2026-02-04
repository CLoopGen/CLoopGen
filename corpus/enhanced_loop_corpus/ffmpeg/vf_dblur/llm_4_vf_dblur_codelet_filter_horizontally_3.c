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
    g = q * dst[y * width] + c * dst[y * width];
    for (int x = 0; x < width; x++) {
        if (x > 0) {
            dst[y * width + x] = b0 * dst[y * width + x] + b1 * dst[(y + 1) * width + x] + g;
            g = q * dst[y * width + x] + c * dst[(y + 1) * width + x];
        } else {
            dst[y * width + x] = b0 * dst[y * width + x] + b1 * dst[(y + 1) * width + x] + g;
            g = q * dst[y * width + x] + c * dst[y * width + x];
        }
    }
}
}
