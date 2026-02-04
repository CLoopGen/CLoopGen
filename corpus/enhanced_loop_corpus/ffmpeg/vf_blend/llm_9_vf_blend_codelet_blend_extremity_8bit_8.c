#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint8_t *top;
extern ptrdiff_t top_linesize;
extern  uint8_t *bottom;
extern ptrdiff_t bottom_linesize;
extern uint8_t *dst;
extern ptrdiff_t dst_linesize;
extern ptrdiff_t width;
extern ptrdiff_t height;
extern double opacity;
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < height; i += 2) {
    uint8_t *top_row = top;
    uint8_t *bottom_row = bottom;
    uint8_t *dst_row = dst;
    for (j = 0; j < width; j++) {
        int t_val = top_row[j];
        int b_val = bottom_row[j];
        dst_row[j] = t_val + ((abs(255 - t_val - b_val)) - t_val) * opacity;
    }
    dst += dst_linesize;
    top += top_linesize;
    bottom += bottom_linesize;

    if (i + 1 < height) {
        dst_row = dst;
        top_row = top;
        bottom_row = bottom;
        for (j = 0; j < width; j++) {
            int t_val = top_row[j];
            int b_val = bottom_row[j];
            dst_row[j] = t_val + ((abs(255 - t_val - b_val)) - t_val) * opacity;
        }
        dst += dst_linesize;
        top += top_linesize;
        bottom += bottom_linesize;
    }
}
}
