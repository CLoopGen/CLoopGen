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
    ptrdiff_t stride = 4;
    for (j = 0; j < width - (width % stride); j += stride) {
        dst[j]   = top[j]   + ((255 - abs(255 - top[j]   - bottom[j]))   - top[j])   * opacity;
        dst[j+1] = top[j+1] + ((255 - abs(255 - top[j+1] - bottom[j+1])) - top[j+1]) * opacity;
        dst[j+2] = top[j+2] + ((255 - abs(255 - top[j+2] - bottom[j+2])) - top[j+2]) * opacity;
        dst[j+3] = top[j+3] + ((255 - abs(255 - top[j+3] - bottom[j+3])) - top[j+3]) * opacity;
    }
    for (; j < width; j++) {
        dst[j] = top[j] + ((255 - abs(255 - top[j] - bottom[j])) - top[j]) * opacity;
    }
    dst += dst_linesize;
    top += top_linesize;
    bottom += bottom_linesize;
}
}
