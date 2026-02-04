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
            uint16_t temp_top1 = top[j];
            uint16_t temp_bot1 = bottom[j];
            uint16_t temp_top2 = top[width + j];
            uint16_t temp_bot2 = bottom[width + j];

            dst[j] = temp_top1 + ((((4095 - temp_top1 - temp_bot1) >= 0 ? (4095 - temp_top1 - temp_bot1) : (-(4095 - temp_top1 - temp_bot1)))) - temp_top1) * opacity;
            dst[width + j] = temp_top2 + ((((4095 - temp_top2 - temp_bot2) >= 0 ? (4095 - temp_top2 - temp_bot2) : (-(4095 - temp_top2 - temp_bot2)))) - temp_top2) * opacity;
        }
        dst += 2 * dst_linesize;
        top += 2 * top_linesize;
        bottom += 2 * bottom_linesize;
    } else {
        for (j = 0; j < width; j++) {
            dst[j] = top[j] + ((((4095 - top[j] - bottom[j]) >= 0 ? (4095 - top[j] - bottom[j]) : (-(4095 - top[j] - bottom[j])))) - top[j]) * opacity;
        }
        dst += dst_linesize;
        top += top_linesize;
        bottom += bottom_linesize;
    }
}
}
