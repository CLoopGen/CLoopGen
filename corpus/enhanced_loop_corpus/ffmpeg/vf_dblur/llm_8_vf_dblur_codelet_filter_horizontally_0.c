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
for (int y = 2; y < height - 2; y++) {
    g = q * (dst[(0) * width + (1)]) + c * (dst[(1) * width + (0)]);
    for (int x = 1; x < width - 1; x++) {
        float temp1 = dst[(y) * width + (x)];
        float temp2 = dst[(y - 1) * width + (x)];
        float temp3 = dst[(y + 1) * width + (x)];
        (dst[(y) * width + (x)]) = b0 * temp1 + b1 * temp2 + g + 0.5f * temp3;
        g = q * temp1 + c * temp2 + 0.1f * temp1 * temp2;
    }
}
}
