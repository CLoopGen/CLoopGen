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
    uint16_t* dst_row = dst;
    uint16_t* top_row = top;
    uint16_t* bottom_row = bottom;
    for (i = 0; i < height; i++) {
        for (j = 0; j < width; j++) {
            uint16_t base = top_row[j];
            uint16_t contrib;
            if (base == 65535) {
                contrib = base;
            } else {
                uint32_t num = (uint32_t)bottom_row[j] * bottom_row[j];
                uint16_t div_result = (num / (65535 - base));
                contrib = (div_result > 65535) ? 65535 : div_result;
            }
            dst_row[j] = base + (contrib - base) * opacity;
        }
        dst_row += dst_linesize;
        top_row += top_linesize;
        bottom_row += bottom_linesize;
    }
}
