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
    for (j = 0; j < width; j += 2) {
        int j2 = j + 1;
        uint16_t top_val1 = top[j];
        uint16_t bot_val1 = bottom[j];
        uint16_t top_val2 = (j2 < width) ? top[j2] : top_val1;
        uint16_t bot_val2 = (j2 < width) ? bottom[j2] : bot_val1;

        uint16_t comp1 = (top_val1 == 0) ? top_val1 : 
                         ((0 > (1023 - ((1023 - bot_val1) << 10) / top_val1)) ? 0 : 
                          (1023 - ((1023 - bot_val1) << 10) / top_val1));
        uint16_t comp2 = (top_val2 == 0) ? top_val2 : 
                         ((0 > (1023 - ((1023 - bot_val2) << 10) / top_val2)) ? 0 : 
                          (1023 - ((1023 - bot_val2) << 10) / top_val2));

        dst[j] = top_val1 + (comp1 - top_val1) * opacity;
        if (j2 < width) {
            dst[j2] = top_val2 + (comp2 - top_val2) * opacity;
        }
    }
    dst += dst_linesize;
    top += top_linesize;
    bottom += bottom_linesize;
}
}
