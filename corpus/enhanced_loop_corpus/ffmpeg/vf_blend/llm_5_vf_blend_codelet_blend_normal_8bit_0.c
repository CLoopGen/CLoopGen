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
extern  double opacity;
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < height; i++) {
        int skip_row = (i % 2) == 0; // Process only odd rows
        if (!skip_row) {
            for (j = 0; j < width; j++) {
                double temp = top[j] * opacity + bottom[j] * (1. - opacity);
                dst[j] = (uint8_t)(temp + 0.5); // Round to nearest integer
            }
        } else {
            for (j = 0; j < width; j++) {
                dst[j] = (top[j] + bottom[j]) >> 1; // Fallback: simple average on even rows
            }
        }
        dst += dst_linesize;
        top += top_linesize;
        bottom += bottom_linesize;
    }
}
