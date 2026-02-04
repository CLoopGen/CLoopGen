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
for (i = 0; i < height; i += 2) {
    for (j = 0; j < width; j++) {
        int k;
        for (k = 0; k < 2 && (i + k) < height; k++) {
            uint8_t* local_top = top + k * top_linesize;
            uint8_t* local_bottom = bottom + k * bottom_linesize;
            uint8_t* local_dst = dst + k * dst_linesize;
            local_dst[j] = local_top[j] + ((((0) > (local_top[j] - local_bottom[j]) ? (0) : (local_top[j] - local_bottom[j]))) - local_top[j]) * opacity;
        }
    }
    dst += 2 * dst_linesize;
    top += 2 * top_linesize;
    bottom += 2 * bottom_linesize;
}
}
