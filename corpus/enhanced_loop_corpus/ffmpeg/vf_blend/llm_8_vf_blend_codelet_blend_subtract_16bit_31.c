#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern ptrdiff_t top_linesize;
extern ptrdiff_t bottom_linesize;
extern ptrdiff_t dst_linesize;
extern ptrdiff_t width;
extern ptrdiff_t height;
extern  uint16_t *top;
extern  uint16_t *bottom;
extern uint16_t *dst;
extern double opacity;
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < height; i++) {
    ptrdiff_t offset = i * width;
    for (j = 0; j < width; j++) {
        ptrdiff_t idx = offset + j;
        int16_t diff = top[j] - bottom[j];
        int16_t clamped_diff = diff > 0 ? diff : 0;
        dst[idx] = (uint16_t)(top[j] + (clamped_diff - top[j]) * opacity);
    }
}
}
