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
    for (j = 0; j < width; j++) {
        uint8_t t1 = top[j], b1 = bottom[j];
        uint8_t t2 = (i + 1 < height) ? top[top_linesize + j] : t1;
        uint8_t b2 = (i + 1 < height) ? bottom[bottom_linesize + j] : b1;

        // First row computation
        int base1 = 2 * t1;
        int comp1 = (t1 < 128) ?
            ((base1 == 0) ? 0 : ((0 > (255 - ((255 - b1) << 8) / base1)) ? 0 : (255 - ((255 - b1) << 8) / base1))) :
            (((2 * (t1 - 128)) == 255) ? 255 : ((255 > ((b1 << 8) / (255 - 2*(t1-128)))) ? ((b1 << 8) / (255 - 2*(t1-128))) : 255));
        dst[j] = t1 + (comp1 - t1) * opacity;

        // Second row computation (if valid)
        if (i + 1 < height) {
            int base2 = 2 * t2;
            int comp2 = (t2 < 128) ?
                ((base2 == 0) ? 0 : ((0 > (255 - ((255 - b2) << 8) / base2)) ? 0 : (255 - ((255 - b2) << 8) / base2))) :
                (((2 * (t2 - 128)) == 255) ? 255 : ((255 > ((b2 << 8) / (255 - 2*(t2-128)))) ? ((b2 << 8) / (255 - 2*(t2-128))) : 255));
            dst[dst_linesize + j] = t2 + (comp2 - t2) * opacity;
        }
    }
    dst += 2 * dst_linesize;
    top += 2 * top_linesize;
    bottom += 2 * bottom_linesize;
}
}
