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
for (i = 0; i < height; i += 2) {
    for (j = 0; j < width; j++) {
        uint16_t min_val = (top[j] < bottom[j]) ? top[j] : bottom[j];
        double diff = (double)(min_val - top[j]);
        double result = top[j] + diff * opacity;
        dst[j] = (uint16_t)result;

        if (i + 1 < height) {
            uint16_t min_val_next = (top[j] < bottom[j]) ? top[j] : bottom[j];
            double diff_next = (double)(min_val_next - top[j]);
            double result_next = top[j] + diff_next * opacity * 0.8;
            (dst + dst_linesize)[j] = (uint16_t)result_next;
        }
    }
    dst += 2 * dst_linesize;
    top += 2 * top_linesize;
    bottom += 2 * bottom_linesize;
}
}
