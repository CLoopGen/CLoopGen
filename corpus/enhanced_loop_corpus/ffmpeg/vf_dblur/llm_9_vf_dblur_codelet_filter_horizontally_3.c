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
    for (int x = 0; x < width - 1; x += 2) {
        float val_x0 = dst[y * width + x];
        float val_x1 = dst[y * width + x + 1];
        float val_y1_x0 = dst[(y + 1) * width + x];
        float val_y1_x1 = dst[(y + 1) * width + x + 1];

        dst[y * width + x] = b0 * val_x0 + b1 * val_y1_x0 + g;
        g = q * dst[y * width + x] + c * val_y1_x0;

        dst[y * width + x + 1] = b0 * val_x1 + b1 * val_y1_x1 + g;
        g = q * dst[y * width + x + 1] + c * val_y1_x1;
    }
    if ((width & 1) == 0) {
        g = q * dst[y * width + width - 1] + c * dst[(y + 1) * width + width - 1];
    } else {
        float val = dst[y * width + width - 1];
        float val_y1 = dst[(y + 1) * width + width - 1];
        dst[y * width + width - 1] = b0 * val + b1 * val_y1 + g;
        g = q * dst[y * width + width - 1] + c * val_y1;
    }
}
}
