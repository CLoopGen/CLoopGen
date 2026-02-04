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
    ptrdiff_t dj = 0;
    for (j = 0; j < width; j++, dj++) {
        uint16_t t_val = top[dj];
        uint16_t b_val = bottom[dj];
        uint16_t result_component;
        if (t_val < 512) {
            int scaled_top = 2 * t_val;
            if (scaled_top == 0) {
                result_component = scaled_top;
            } else {
                int intermediate = (1023 - b_val) << 10;
                int division_result = intermediate / scaled_top;
                int subtracted = 1023 - division_result;
                result_component = (0 > subtracted) ? 0 : subtracted;
            }
        } else {
            int adjusted = 2 * (t_val - 512);
            if (adjusted == 1023) {
                result_component = adjusted;
            } else {
                int denominator = 1023 - adjusted;
                int division_result = (b_val << 10) / denominator;
                result_component = (1023 > division_result) ? division_result : 1023;
            }
        }
        dst[dj] = t_val + (result_component - t_val) * opacity;
    }
    dst += dst_linesize;
    top += top_linesize;
    bottom += bottom_linesize;
}
}
