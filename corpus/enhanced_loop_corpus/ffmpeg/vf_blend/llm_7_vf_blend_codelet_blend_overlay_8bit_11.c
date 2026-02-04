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
    uint8_t adjusted_top, computed_result;
    ptrdiff_t k;
    for (i = 0; i < height; i++) {
        for (k = 0; k < width; k++) {
            j = width - 1 - k; // Reverse access order: introduces WAR dependency by changing access pattern
            adjusted_top = top[j];
            computed_result = (adjusted_top < 128) ?
                (2 * (adjusted_top * bottom[j]) / 255) :
                (255 - 2 * ((255 - adjusted_top) * (255 - bottom[j]) / 255));
            dst[j] = adjusted_top + (computed_result - adjusted_top) * opacity;
        }
        dst += dst_linesize;
        top += top_linesize;
        bottom += bottom_linesize;
    }
}
