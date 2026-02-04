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
        uint8_t computed;

        // Eliminated conditional by using arithmetic logic to compute clamp
        ptrdiff_t denominator = 255 - b;
        double inv_denom = (denominator == 0) ? 1.0 : (1.0 / denominator);
        double scaled = (b == 255) ? 255.0 : (double)(t * t) * inv_denom;
        computed = (scaled > 255.0) ? 255 : (uint8_t)scaled;

        dst[j] = t + (computed - t) * opacity;
    }
    dst += dst_linesize;
    top += top_linesize;
    bottom += bottom_linesize;
}
}
