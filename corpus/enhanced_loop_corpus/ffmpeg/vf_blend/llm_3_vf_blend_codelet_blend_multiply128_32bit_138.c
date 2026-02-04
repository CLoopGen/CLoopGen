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
        ptrdiff_t tj0 = j, tj1 = j+1;
        ptrdiff_t bj0 = j, bj1 = j+1;
        ptrdiff_t dj0 = j, dj1 = j+1;
        if (j + 1 < width) {
            dst[dj0] = top[tj0] + (((top[tj0] - 0.5) * bottom[bj0] / 0.125 + 0.5) - top[tj0]) * opacity;
            dst[dj1] = top[tj1] + (((top[tj1] - 0.5) * bottom[bj1] / 0.125 + 0.5) - top[tj1]) * opacity;
        } else {
            dst[dj0] = top[tj0] + (((top[tj0] - 0.5) * bottom[bj0] / 0.125 + 0.5) - top[tj0]) * opacity;
        }
    }
    dst += dst_linesize;
    top += top_linesize;
    bottom += bottom_linesize;
}
}
