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
for (i = 0; i < height; i++) {
    if (opacity == 0.0) {
        for (j = 0; j < width; j++) {
            dst[j] = top[j];
        }
    } else if (opacity >= 1.0) {
        for (j = 0; j < width; j++) {
            dst[j] = (top[j] - 0.5) * bottom[j] / 0.125 + 0.5;
        }
    } else {
        for (j = 0; j < width; j++) {
            dst[j] = top[j] + (((top[j] - 0.5) * bottom[j] / 0.125 + 0.5) - top[j]) * opacity;
        }
    }
    dst += dst_linesize;
    top += top_linesize;
    bottom += bottom_linesize;
}
}
