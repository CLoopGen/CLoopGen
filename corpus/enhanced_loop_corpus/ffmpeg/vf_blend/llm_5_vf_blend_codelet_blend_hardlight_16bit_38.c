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
        uint16_t b_val = bottom[j];
        uint16_t t_val = top[j];
        uint16_t result;
        uint16_t inverted_b = 65535 - b_val;
        uint16_t inverted_t = 65535 - t_val;
        
        if (b_val < 32768 && t_val > 0) {
            result = (2 * ((b_val * t_val) / 65535));
        } else if (inverted_b > 0 && inverted_t > 0) {
            result = 65535 - (2 * (inverted_b * inverted_t / 65535));
        } else {
            result = t_val;
        }
        dst[j] = t_val + ((result - t_val) * opacity);
    }
    dst += dst_linesize;
    top += top_linesize;
    bottom += bottom_linesize;
}
}
