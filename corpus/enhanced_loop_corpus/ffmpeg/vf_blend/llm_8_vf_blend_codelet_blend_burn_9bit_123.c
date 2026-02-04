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
        int k = j + 1;
        uint16_t top_val1 = top[j], bottom_val1 = bottom[j];
        uint16_t top_val2 = (k < width) ? top[k] : top_val1;
        uint16_t bottom_val2 = (k < width) ? bottom[k] : bottom_val1;

        uint16_t comp1 = (top_val1 == 0) ? top_val1 : 
                         (0 > (511 - ((511 - bottom_val1) << 9) / top_val1) ? 0 : 
                         (511 - ((511 - bottom_val1) << 9) / top_val1));
        dst[j] = top_val1 + (comp1 - top_val1) * opacity;

        if (k < width) {
            uint16_t comp2 = (top_val2 == 0) ? top_val2 : 
                             (0 > (511 - ((511 - bottom_val2) << 9) / top_val2) ? 0 : 
                             (511 - ((511 - bottom_val2) << 9) / top_val2));
            dst[k] = top_val2 + (comp2 - top_val2) * opacity;
        }
    }
    dst += dst_linesize;
    top += top_linesize;
    bottom += bottom_linesize;
}
}
