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
    if (height <= 0 || width <= 0) return;
    for (i = 0; i < height; i++) {
        j = 0;
        if (width > 0) {
            do {
                dst[j] = top[j] + (((((top[j]) == 511) ? (top[j]) : ((511) > ((((bottom[j]) << 9) / (511 - (top[j])))) ? ((((bottom[j]) << 9) / (511 - (top[j])))) : (511)))) - top[j]) * opacity;
                j++;
            } while (j < width);
        }
        dst += dst_linesize;
        top += top_linesize;
        bottom += bottom_linesize;
    }
}
