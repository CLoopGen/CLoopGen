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
    for (int x = width - 1; x >= 0; x--) {
        float temp;
        if (x == width - 1) {
            temp = q * (dst[(0) * width + (width - 1)]) + c * (dst[(0) * width + (width - 1)]);
        } else {
            temp = q * (dst[(y) * width + (x + 1)]) + c * (dst[(y - 1) * width + (x + 1)]);
        }
        (dst[(y) * width + (x)]) = b0 * (dst[(y) * width + (x)]) + b1 * (dst[(y - 1) * width + (x)]) + temp;
    }
}
}
