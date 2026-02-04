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
    for (j = 0; j < width; j += stride) {
        for (int k = 0; k < stride && (j + k) < width; ++k) {
            int idx = j + k;
            int t = top[idx];
            int b = bottom[idx];
            int blended = t + (((b < t ? b : t) - (b > t ? b : t) + 255) - t) * opacity;
            dst[idx] = (uint8_t)((blended * 0.9) + (t * 0.1));
        }
    }
    dst += dst_linesize;
    top += top_linesize;
    bottom += bottom_linesize;
}
}
