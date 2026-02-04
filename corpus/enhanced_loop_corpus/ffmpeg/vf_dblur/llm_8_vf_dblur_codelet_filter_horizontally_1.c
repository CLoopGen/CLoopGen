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
    if (y < 1) break;
    float g1 = q * dst[y * width + (width - 1)] + c * dst[y * width + (width - 1)];
    float g2 = q * dst[(y-1) * width + (width - 1)] + c * dst[(y-1) * width + (width - 1)];
    for (int x = width - 1; x >= 0; x--) {
        dst[y * width + x] = b0 * dst[y * width + x] + b1 * dst[(y+1) * width + x] + g1;
        g1 = q * dst[y * width + x] + c * dst[(y+1) * width + x];
        
        if (y > 0) {
            dst[(y-1) * width + x] = b0 * dst[(y-1) * width + x] + b1 * dst[y * width + x] + g2;
            g2 = q * dst[(y-1) * width + x] + c * dst[y * width + x];
        }
    }
}
}
