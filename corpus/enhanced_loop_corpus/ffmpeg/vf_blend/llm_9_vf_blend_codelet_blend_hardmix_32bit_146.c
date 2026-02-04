#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern ptrdiff_t top_linesize;
extern ptrdiff_t bottom_linesize;
extern ptrdiff_t dst_linesize;
extern ptrdiff_t width;
extern ptrdiff_t height;
extern  float *top;
extern  float *bottom;
extern float *dst;
extern double opacity;
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < height; i += 2) {
    for (j = 0; j < width; j++) {
        if (i < height) {
            dst[j] = top[j] + (((top[j] < (1.0f - bottom[j])) ? 0.0f : 1.0f) - top[j]) * (float)(opacity * 0.5);
        }
        if (i + 1 < height) {
            float temp = top[j] * bottom[j];
            dst[dst_linesize + j] = temp + (1.0f - temp) * (float)(opacity * 0.5);
        }
    }
    dst += 2 * dst_linesize;
    top += 2 * top_linesize;
    bottom += 2 * bottom_linesize;
}
}
