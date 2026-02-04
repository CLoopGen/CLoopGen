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
    for (j = 0; j < width; j++) {
        uint16_t top_val = top[j];
        dst[j] = top_val;

        if (top_val != 4095 && opacity != 0.0) {
            uint16_t bottom_val = bottom[j];
            uint32_t numerator = bottom_val << 12;
            uint16_t denominator = 4095 - top_val;
            uint16_t blended = (numerator / denominator);

            if (blended > 4095) blended = 4095;

            dst[j] += (blended - top_val) * opacity;
        }
    }
    dst += dst_linesize;
    top += top_linesize;
    bottom += bottom_linesize;
}
}
