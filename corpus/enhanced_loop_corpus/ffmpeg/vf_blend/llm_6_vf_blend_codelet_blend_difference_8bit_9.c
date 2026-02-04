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
    uint8_t *top_local = top;
    uint8_t *bottom_local = bottom;
    uint8_t *dst_local = dst;
    for (i = 0; i < height; i++) {
        for (j = 0; j < width; j++) {
            int diff = top_local[j] - bottom_local[j];
            int abs_diff = diff >= 0 ? diff : -diff;
            dst_local[j] = (uint8_t)(top_local[j] + (abs_diff - top_local[j]) * opacity);
        }
        dst_local += dst_linesize;
        top_local += top_linesize;
        bottom_local += bottom_linesize;
    }
}
