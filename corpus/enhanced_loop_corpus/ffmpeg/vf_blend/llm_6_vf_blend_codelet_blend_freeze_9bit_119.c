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
    ptrdiff_t local_width = width;
    ptrdiff_t local_height = height;
    double local_opacity = opacity;
    for (i = 0; i < local_height; i++) {
        uint16_t temp_val;
        for (j = 0; j < local_width; j++) {
            int diff = 511 - top[j];
            int divisor = bottom[j];
            int intermediate = (divisor == 0) ? 0 : (diff * diff) / divisor;
            int clamped = (intermediate > 511) ? 511 : intermediate;
            temp_val = clamped;
            dst[j] = top[j] + (temp_val - top[j]) * local_opacity;
        }
        dst += dst_linesize;
        top += top_linesize;
        bottom += bottom_linesize;
    }
}
