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
    for (j = 0; j < width; j++) {
        float diff = top[j] - bottom[j];
        float abs_diff = diff;
        if (diff >= 0) {
            abs_diff = diff;
        } else {
            abs_diff = -diff;
        }
        float contribution = (abs_diff - top[j]) * opacity;
        if (contribution > -1e-6 && contribution < 1e-6) {
            dst[j] = top[j];
        } else {
            dst[j] = top[j] + contribution;
        }
    }
    dst += dst_linesize;
    top += top_linesize;
    bottom += bottom_linesize;
}
}
