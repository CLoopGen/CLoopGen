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
    for (j = 0; j < width; j += 2) {
        ptrdiff_t tj0 = i * top_linesize + j;
        ptrdiff_t bj0 = i * bottom_linesize + j;
        ptrdiff_t dj0 = i * dst_linesize + j;
        ptrdiff_t tj1 = tj0 + 1;
        ptrdiff_t bj1 = bj0 + 1;
        ptrdiff_t dj1 = dj0 + 1;

        if (j + 1 < width) {
            dst[dj0] = top[tj0] + (((((top[tj0]) == 4095) ? (top[tj0]) : ((4095) > ((((bottom[bj0]) << 12) / (4095 - (top[tj0])))) ? ((((bottom[bj0]) << 12) / (4095 - (top[tj0])))) : (4095)))) - top[tj0]) * opacity;
            dst[dj1] = top[tj1] + (((((top[tj1]) == 4095) ? (top[tj1]) : ((4095) > ((((bottom[bj1]) << 12) / (4095 - (top[tj1])))) ? ((((bottom[bj1]) << 12) / (4095 - (top[tj1])))) : (4095)))) - top[tj1]) * opacity;
        } else {
            dst[dj0] = top[tj0] + (((((top[tj0]) == 4095) ? (top[tj0]) : ((4095) > ((((bottom[bj0]) << 12) / (4095 - (top[tj0])))) ? ((((bottom[bj0]) << 12) / (4095 - (top[tj0])))) : (4095)))) - top[tj0]) * opacity;
        }
    }
}
}
