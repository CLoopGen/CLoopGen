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
    for (j = 0; j < width; j++) {
        uint16_t term;
        uint16_t b_val = bottom[j];
        uint16_t t_val = top[j];
        ptrdiff_t offset = b_val - 2048;
        int is_above_threshold = b_val >= 2048;

        if (is_above_threshold && (t_val <= 2 * offset)) {
            term = 2 * offset;
        } else if (is_above_threshold) {
            term = t_val;
        } else if (t_val > 2 * b_val) {
            term = 2 * b_val;
        } else {
            term = t_val;
        }

        dst[j] = t_val + (term - t_val) * opacity;
    }
    dst += dst_linesize;
    top += top_linesize;
    bottom += bottom_linesize;
}
}
