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
        uint16_t t = top[j];
        uint16_t b = bottom[j];
        int base_val, blend;

        // Eliminate nested ternary by precomputing branch condition
        if (t < 512) {
            int twice_t = 2 * t;
            if (twice_t == 0) {
                blend = 0;
            } else {
                int intermediate = (1023 - b) << 10;
                int div_result = intermediate / twice_t;
                blend = (1023 - div_result) > 0 ? (1023 - div_result) : 0;
                if (blend > 1023) blend = 1023;
            }
        } else {
            int adjusted = 2 * (t - 512);
            if (adjusted == 1023) {
                blend = 1023;
            } else {
                int denom = 1023 - adjusted;
                if (denom == 0) {
                    blend = 1023;
                } else {
                    blend = (b << 10) / denom;
                    if (blend > 1023) blend = 1023;
                }
            }
        }

        base_val = t + (int)((blend - t) * opacity);
        dst[j] = (base_val < 0) ? 0 : ((base_val > 1023) ? 1023 : base_val);
    }
    dst += dst_linesize;
    top += top_linesize;
    bottom += bottom_linesize;
}
}
