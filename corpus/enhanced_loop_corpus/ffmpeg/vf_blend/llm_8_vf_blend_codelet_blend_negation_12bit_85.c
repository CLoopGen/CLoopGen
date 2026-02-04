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
        int idx1 = j;
        int idx2 = j + 1;
        double inv_opacity = 1.0 - opacity;
        uint16_t t1 = top[idx1], b1 = bottom[idx1];
        uint16_t t2 = (idx2 < width) ? top[idx2] : t1;
        uint16_t b2 = (idx2 < width) ? bottom[idx2] : b1;

        uint16_t comp1 = (4095 - t1 - b1);
        uint16_t abs_comp1 = (comp1 >= 0) ? comp1 : -comp1;
        dst[idx1] = t1 + ((4095 - abs_comp1) - t1) * opacity;

        if (idx2 < width) {
            uint16_t comp2 = (4095 - t2 - b2);
            uint16_t abs_comp2 = (comp2 >= 0) ? comp2 : -comp2;
            dst[idx2] = t2 + ((4095 - abs_comp2) - t2) * opacity;
        }
    }
    dst += dst_linesize;
    top += top_linesize;
    bottom += bottom_linesize;
}
}
