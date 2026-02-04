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
        uint16_t t_val = top[j];
        uint16_t b_val = bottom[j];
        uint16_t result;
        if (t_val == 4095) {
            result = t_val;
        } else {
            uint16_t computed = (b_val * b_val) / (4095 - t_val);
            result = (computed > 4095) ? 4095 : computed;
        }
        dst[j] = t_val + (result - t_val) * opacity;
    }
    dst += dst_linesize;
    top += top_linesize;
    bottom += bottom_linesize;
}
}
