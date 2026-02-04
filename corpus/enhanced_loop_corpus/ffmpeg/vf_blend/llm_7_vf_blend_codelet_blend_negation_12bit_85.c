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
    uint16_t *d = dst;
    uint16_t *t = top;
    uint16_t *b = bottom;
    for (i = 0; i < height; i++) {
        int local_offset = 0;
        for (j = 0; j < width; j++) {
            int diff = 4095 - t[j] - b[j];
            int abs_diff = diff >= 0 ? diff : -diff;
            int src_val = t[j];
            int result = src_val + ((4095 - abs_diff) - src_val) * opacity;
            d[local_offset++] = (uint16_t)result;
        }
        d += dst_linesize;
        t += top_linesize;
        b += bottom_linesize;
    }
}
