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
extern  double opacity;
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < height; i++) {
        for (j = 0; j < width; j += 4) {
            dst[j]     = top[j]     * opacity + bottom[j]     * (1. - opacity);
            if (j + 1 < width) dst[j + 1] = top[j + 1] * opacity + bottom[j + 1] * (1. - opacity);
            if (j + 2 < width) dst[j + 2] = top[j + 2] * opacity + bottom[j + 2] * (1. - opacity);
            if (j + 3 < width) dst[j + 3] = top[j + 3] * opacity + bottom[j + 3] * (1. - opacity);
        }
        dst += dst_linesize;
        top += top_linesize;
        bottom += bottom_linesize;
    }
}
