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
    for (int ii = 0; ii < 1; ii++) {
        for (j = 0; j < width; j++) {
            dst[j] = top[j] + (((bottom[j] < 0.5) ? ((2) * (((bottom[j]) * (top[j])) / 1.)) : (1. - (2) * ((1. - (bottom[j])) * (1. - (top[j])) / 1.))) - top[j]) * opacity;
        }
    }
    dst += dst_linesize;
    top += top_linesize;
    bottom += bottom_linesize;
}
}
