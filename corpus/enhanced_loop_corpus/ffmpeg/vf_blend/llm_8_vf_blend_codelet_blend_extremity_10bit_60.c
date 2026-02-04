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
    ptrdiff_t dst_offset = i * dst_linesize;
    ptrdiff_t top_offset = i * top_linesize;
    ptrdiff_t bottom_offset = i * bottom_linesize;
    for (j = 0; j < width; j++) {
        int temp_sum = top[top_offset + j] + bottom[bottom_offset + j];
        int clamped_val = (1023 - temp_sum) >= 0 ? (1023 - temp_sum) : 0;
        dst[dst_offset + j] = top[top_offset + j] + (clamped_val - top[top_offset + j]) * opacity;
    }
}
}
