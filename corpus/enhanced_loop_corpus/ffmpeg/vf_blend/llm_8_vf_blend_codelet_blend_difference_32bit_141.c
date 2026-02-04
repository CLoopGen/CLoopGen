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
    for (j = 0; j < width; j += 2) {
        float diff1 = top[j] - bottom[j];
        float abs_diff1 = diff1 >= 0 ? diff1 : -diff1;
        dst[j] = top[j] + (abs_diff1 - top[j]) * opacity;

        if (j + 1 < width) {
            float diff2 = top[j+1] - bottom[j+1];
            float abs_diff2 = diff2 >= 0 ? diff2 : -diff2;
            dst[j+1] = top[j+1] + (abs_diff2 - top[j+1]) * opacity;
        }
    }
    dst += dst_linesize;
    top += top_linesize;
    bottom += bottom_linesize;
}
}
