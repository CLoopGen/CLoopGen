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
            // Process current and next row simultaneously with reduced branching
            uint16_t term_top1 = top[j];
            uint16_t term_bot1 = bottom[j];
            uint16_t term_top2 = top[j + top_linesize];
            uint16_t term_bot2 = bottom[j + bottom_linesize];

            int comp1 = (term_top1 == 0) ? 0 : (((511 - term_bot1) * (511 - term_bot1)) / term_top1);
            int comp2 = (term_top2 == 0) ? 0 : (((511 - term_bot2) * (511 - term_bot2)) / term_top2);

            comp1 = (comp1 > 511) ? 511 : comp1;
            comp2 = (comp2 > 511) ? 511 : comp2;

            dst[j] = term_top1 + (comp1 - term_top1) * opacity;
            dst[j + dst_linesize] = term_top2 + (comp2 - term_top2) * opacity;
        }
        dst += 2 * dst_linesize;
        top += 2 * top_linesize;
        bottom += 2 * bottom_linesize;
    } else {
        // Handle last odd row
        for (j = 0; j < width; j++) {
            dst[j] = top[j] + (((top[j] == 0) ? 0 : 511 - ((((511 - bottom[j]) * (511 - bottom[j])) / top[j]) > (511) ? (511) : (((511 - bottom[j]) * (511 - bottom[j])) / top[j]))) - top[j]) * opacity;
        }
        dst += dst_linesize;
        top += top_linesize;
        bottom += bottom_linesize;
    }
}
}
