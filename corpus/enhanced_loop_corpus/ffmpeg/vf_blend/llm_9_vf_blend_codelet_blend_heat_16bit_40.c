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
        uint32_t inv_bottom = 65535 - bottom[j];
        uint32_t diff_sq = inv_bottom * inv_bottom;
        uint32_t div_result = (top[j] == 0) ? 0 : diff_sq / top[j];
        uint16_t blended = (div_result > 65535) ? 0 : div_result;
        dst[j] = top[j] + ((blended - top[j]) * opacity);
    }
    dst += dst_linesize;
    top += top_linesize;
    bottom += bottom_linesize;

    if (i + 1 < height) {
        for (j = 0; j < width; j++) {
            uint32_t inv_bottom_next = 65535 - bottom[j];
            uint32_t diff_sq_next = inv_bottom_next * inv_bottom_next;
            uint32_t div_result_next = (top[j] == 0) ? 0 : diff_sq_next / top[j];
            uint16_t blended_next = (div_result_next > 65535) ? 0 : div_result_next;
            dst[j] = top[j] + ((blended_next - top[j]) * opacity);
        }
        dst += dst_linesize;
        top += top_linesize;
        bottom += bottom_linesize;
    }
}
}
