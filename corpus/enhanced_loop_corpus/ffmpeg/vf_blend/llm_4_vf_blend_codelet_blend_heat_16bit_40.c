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
        uint16_t top_val = top[j];
        uint16_t bottom_val = bottom[j];
        uint32_t inv_bottom_sq = (65535 - bottom_val);
        inv_bottom_sq = inv_bottom_sq * inv_bottom_sq;
        uint32_t div_result = (top_val == 0) ? 0 : (inv_bottom_sq / top_val);
        uint32_t clamped_val = div_result > 65535 ? 65535 : div_result;
        dst[j] = top_val + ((top_val == 0 ? 0 : 65535 - clamped_val) - top_val) * opacity;
    }
    dst += dst_linesize;
    top += top_linesize;
    bottom += bottom_linesize;
}
}
