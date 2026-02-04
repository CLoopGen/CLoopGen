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
        uint16_t result;

        // Remove conditional ternary and use arithmetic to compute condition mask
        ptrdiff_t is_max = (b == 4095) * 4095;
        ptrdiff_t not_max = (b != 4095);
        ptrdiff_t safe_denom = (4095 - b) + !not_max; // prevent division by zero, though logically not needed due to mask
        ptrdiff_t computed = not_max * ((t * t) / safe_denom);
        ptrdiff_t clamped = computed > 4095 ? 4095 : computed;
        result = is_max + not_max * clamped;

        dst[j] = t + (result - t) * opacity;
    }
    dst += dst_linesize;
    top += top_linesize;
    bottom += bottom_linesize;
}
}
