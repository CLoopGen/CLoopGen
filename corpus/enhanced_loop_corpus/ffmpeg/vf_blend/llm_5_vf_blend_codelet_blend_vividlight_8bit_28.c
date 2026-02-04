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
for (i = 0; i < height; i++) {
    for (j = 0; j < width; j++) {
        uint8_t t = top[j];
        uint8_t b = bottom[j];
        int result;
        int factor = 2 * t;
        if (t < 128 && factor != 0) {
            int comp = (255 - ((255 - b) << 8) / factor);
            result = (comp < 0) ? 0 : (comp > 255 ? 255 : comp);
        } else if (t >= 128) {
            int adj = 2 * (t - 128);
            if (adj >= 255) {
                result = 255;
            } else {
                int denom = 255 - adj;
                int val = (b << 8) / (denom ? denom : 1);
                result = (val > 255) ? 255 : val;
            }
        } else {
            result = 0;
        }
        dst[j] = t + (result - t) * opacity;
    }
    dst += dst_linesize;
    top += top_linesize;
    bottom += bottom_linesize;
}
}
