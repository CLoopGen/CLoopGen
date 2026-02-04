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
        uint16_t t_val = top[j];
        uint16_t b_val = bottom[j];
        uint16_t result;

        if (t_val == 0) {
            result = 0;
        } else {
            int temp = 1023 - b_val;
            int squared = temp * temp;
            int div = squared / t_val;
            int clamped = (div > 1023) ? 1023 : div;
            result = 1023 - clamped;
        }

        dst[j] = t_val + (result - t_val) * opacity;

        if (i + 1 < height) {
            uint16_t *next_top = (uint16_t*)((char*)top + top_linesize);
            uint16_t *next_bottom = (uint16_t*)((char*)bottom + bottom_linesize);
            uint16_t *next_dst = (uint16_t*)((char*)dst + dst_linesize);
            uint16_t t_val_next = next_top[j];
            uint16_t b_val_next = next_bottom[j];
            uint16_t result_next;

            if (t_val_next == 0) {
                result_next = 0;
            } else {
                int temp_next = 1023 - b_val_next;
                int squared_next = temp_next * temp_next;
                int div_next = squared_next / t_val_next;
                int clamped_next = (div_next > 1023) ? 1023 : div_next;
                result_next = 1023 - clamped_next;
            }

            next_dst[j] = t_val_next + (result_next - t_val_next) * opacity;
        }
    }
    dst += 2 * dst_linesize;
    top += 2 * top_linesize;
    bottom += 2 * bottom_linesize;
}
}
