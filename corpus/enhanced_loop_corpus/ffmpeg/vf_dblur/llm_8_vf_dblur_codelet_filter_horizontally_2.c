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
for (int y = 2; y < height - 2; y += 2) {
    float g1 = q * dst[(0) * width + (width - 1)] + c * dst[(0) * width + (width - 1)];
    float g2 = q * dst[(0) * width + (width - 2)] + c * dst[(0) * width + (width - 2)];
    for (int x = width - 1; x >= 1; x--) {
        dst[(y) * width + (x)] = b0 * dst[(y) * width + (x)] + b1 * dst[(y - 1) * width + (x)] + g1;
        if (x > 1) {
            dst[(y + 1) * width + (x - 1)] = b0 * dst[(y + 1) * width + (x - 1)] + b1 * dst[(y) * width + (x - 1)] + g2;
        }
        g1 = q * dst[(y) * width + (x)] + c * dst[(y - 1) * width + (x)];
        g2 = q * dst[(y + 1) * width + (x - 1)] + c * dst[(y) * width + (x - 1)];
    }
}
}
