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
    j = 0;
    if (width > 4) {
        for (; j < width - 4; j += 4) {
            dst[j]   = top[j]   + (((top[j]   - 0.5) * bottom[j]   / 0.125 + 0.5) - top[j])   * opacity;
            dst[j+1] = top[j+1] + (((top[j+1] - 0.5) * bottom[j+1] / 0.125 + 0.5) - top[j+1]) * opacity;
            dst[j+2] = top[j+2] + (((top[j+2] - 0.5) * bottom[j+2] / 0.125 + 0.5) - top[j+2]) * opacity;
            dst[j+3] = top[j+3] + (((top[j+3] - 0.5) * bottom[j+3] / 0.125 + 0.5) - top[j+3]) * opacity;
        }
    }
    for (; j < width; j++) {
        dst[j] = top[j] + (((top[j] - 0.5) * bottom[j] / 0.125 + 0.5) - top[j]) * opacity;
    }
    dst += dst_linesize;
    top += top_linesize;
    bottom += bottom_linesize;
}
}
