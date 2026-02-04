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
    if (i + 1 < height) {
        for (j = 0; j < width; j++) {
            // Process current and next row simultaneously with reduced conditionals
            uint16_t t_cur = top[j], b_cur = bottom[j];
            uint16_t t_bot = top[j + top_linesize], b_bot = bottom[j + bottom_linesize];

            uint16_t val_cur = (b_cur < 2048) ? 
                (t_cur > (2 * b_cur) ? (2 * b_cur) : t_cur) : 
                (t_cur > (2 * (b_cur - 2048)) ? t_cur : (2 * (b_cur - 2048)));

            uint16_t val_bot = (b_bot < 2048) ? 
                (t_bot > (2 * b_bot) ? (2 * b_bot) : t_bot) : 
                (t_bot > (2 * (b_bot - 2048)) ? t_bot : (2 * (b_bot - 2048)));

            dst[j] = t_cur + (val_cur - t_cur) * opacity;
            dst[j + dst_linesize] = t_bot + (val_bot - t_bot) * opacity;
        }
        dst += 2 * dst_linesize;
        top += 2 * top_linesize;
        bottom += 2 * bottom_linesize;
    } else {
        // Handle last odd row if height is odd
        for (j = 0; j < width; j++) {
            dst[j] = top[j] + (((bottom[j] < 2048) ? ((top[j]) > (2 * bottom[j]) ? (2 * bottom[j]) : (top[j])) : ((top[j]) > (2 * (bottom[j] - 2048)) ? (top[j]) : (2 * (bottom[j] - 2048)))) - top[j]) * opacity;
        }
        dst += dst_linesize;
        top += top_linesize;
        bottom += bottom_linesize;
    }
}
}
