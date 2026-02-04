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
    int skip_row = (i % 2) == 0;
    for (j = 0; j < width; j++) {
        if (skip_row && (j % 2 == 1)) {
            dst[j] = top[j];
            continue;
        }
        int sum = top[j] + bottom[j];
        int capped_sum = sum > 4095 ? 4095 : sum;
        int contribution = capped_sum - top[j];
        dst[j] = top[j] + contribution * opacity;
    }
    dst += dst_linesize;
    top += top_linesize;
    bottom += bottom_linesize;
}
}
