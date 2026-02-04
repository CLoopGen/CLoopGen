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
    g = q * dst[(y) * width + (0)] + c * dst[(y - 1) * width + (0)];
    for (int x = 0; x < width; x++) {
        float temp = dst[(y) * width + (x)];
        dst[(y) * width + (x)] = b0 * temp + b1 * dst[(y - 1) * width + (x)] + g;
        g = q * temp + c * dst[(y - 1) * width + (x)];
    }
}
}
