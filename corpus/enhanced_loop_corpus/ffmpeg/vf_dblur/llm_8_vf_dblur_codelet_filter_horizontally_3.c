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
for (int y = height - 2; y >= 0; y -= 2) {
    float g1, g2;
    int y1 = y - 1;
    g1 = q * dst[y * width] + c * dst[y * width];
    if (y1 >= 0) {
        g2 = q * dst[y1 * width] + c * dst[y1 * width];
    }
    for (int x = 0; x < width; x++) {
        dst[y * width + x] = b0 * dst[y * width + x] + b1 * dst[(y + 1) * width + x] + g1;
        g1 = q * dst[y * width + x] + c * dst[(y + 1) * width + x];
        if (y1 >= 0) {
            dst[y1 * width + x] = b0 * dst[y1 * width + x] + b1 * dst[(y1 + 1) * width + x] + g2;
            g2 = q * dst[y1 * width + x] + c * dst[(y1 + 1) * width + x];
        }
    }
}
}
