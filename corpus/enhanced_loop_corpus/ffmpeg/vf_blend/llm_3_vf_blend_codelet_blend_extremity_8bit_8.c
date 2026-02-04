#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint8_t *top;
extern ptrdiff_t top_linesize;
extern  uint8_t *bottom;
extern ptrdiff_t bottom_linesize;
extern uint8_t *dst;
extern ptrdiff_t dst_linesize;
extern ptrdiff_t width;
extern ptrdiff_t height;
extern double opacity;
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < height; i++) {
    for (j = 0; j < width; j += 2) {
        ptrdiff_t idx = j;
        dst[idx] = top[idx] + ((((255 - top[idx] - bottom[idx]) >= 0 ? (255 - top[idx] - bottom[idx]) : (-(255 - top[idx] - bottom[idx])))) - top[idx]) * opacity;
        if (j + 1 < width) {
            idx = j + 1;
            dst[idx] = top[idx] + ((((255 - top[idx] - bottom[idx]) >= 0 ? (255 - top[idx] - bottom[idx]) : (-(255 - top[idx] - bottom[idx])))) - top[idx]) * opacity;
        }
    }
    dst += dst_linesize;
    top += top_linesize;
    bottom += bottom_linesize;
}
}
