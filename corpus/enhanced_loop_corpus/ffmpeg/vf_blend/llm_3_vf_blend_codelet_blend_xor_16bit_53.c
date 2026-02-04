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
    for (j = 0; j < width; j += 4) {
        ptrdiff_t idx0 = j;
        ptrdiff_t idx1 = j + 1;
        ptrdiff_t idx2 = j + 2;
        ptrdiff_t idx3 = j + 3;
        if (idx0 < width) dst[idx0] = top[idx0] + ((top[idx0] ^ bottom[idx0]) - top[idx0]) * opacity;
        if (idx1 < width) dst[idx1] = top[idx1] + ((top[idx1] ^ bottom[idx1]) - top[idx1]) * opacity;
        if (idx2 < width) dst[idx2] = top[idx2] + ((top[idx2] ^ bottom[idx2]) - top[idx2]) * opacity;
        if (idx3 < width) dst[idx3] = top[idx3] + ((top[idx3] ^ bottom[idx3]) - top[idx3]) * opacity;
    }
    dst += dst_linesize;
    top += top_linesize;
    bottom += bottom_linesize;
}
}
