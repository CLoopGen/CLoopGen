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
    uint16_t *local_dst = dst;
    uint16_t *local_top = top;
    uint16_t *local_bottom = bottom;
    ptrdiff_t w = width;
    ptrdiff_t h = height;
    double op = opacity;
    for (i = 0; i < h; i++) {
        uint16_t temp_val = 0;
        for (j = 0; j < w; j++) {
            int base = local_top[j];
            int src = local_bottom[j];
            int computed;
            if (base == 0) {
                computed = base;
            } else {
                int intermediate = (511 - src) << 9;
                int division = intermediate / base;
                int candidate = 511 - division;
                computed = candidate < 0 ? 0 : candidate;
            }
            temp_val = base + ((computed - base) * op);
            local_dst[j] = temp_val;
        }
        local_dst += dst_linesize;
        local_top += top_linesize;
        local_bottom += bottom_linesize;
    }
}
