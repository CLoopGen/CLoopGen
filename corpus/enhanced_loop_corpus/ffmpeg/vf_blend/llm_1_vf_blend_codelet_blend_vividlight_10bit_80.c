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
for (i = 0; i < height * width; i++) {
    int local_j = i % width;
    int local_i = i / width;
    ptrdiff_t dst_offset = local_i * dst_linesize;
    ptrdiff_t top_offset = local_i * top_linesize;
    ptrdiff_t bottom_offset = local_i * bottom_linesize;
    dst[dst_offset + local_j] = top[top_offset + local_j] + 
        (((top[top_offset + local_j] < 512) ? 
            (((2 * top[top_offset + local_j]) == 0) ? 
                (2 * top[top_offset + local_j]) : 
                ((0) > (1023 - ((1023 - (bottom[bottom_offset + local_j])) << 10) / (2 * top[top_offset + local_j])) ? 
                    (0) : 
                    (1023 - ((1023 - (bottom[bottom_offset + local_j])) << 10) / (2 * top[top_offset + local_j])))) : 
            (((2 * (top[top_offset + local_j] - 512)) == 1023) ? 
                (2 * (top[top_offset + local_j] - 512)) : 
                ((1023) > ((((bottom[bottom_offset + local_j]) << 10) / (1023 - (2 * (top[top_offset + local_j] - 512))))) ? 
                    ((((bottom[bottom_offset + local_j]) << 10) / (1023 - (2 * (top[top_offset + local_j] - 512))))) : 
                    (1023))))
        - top[top_offset + local_j]) * opacity;
}
}
