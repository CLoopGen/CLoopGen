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
        uint16_t temp_sum;
        for (j = 0; j < local_width; j++) {
            temp_sum = top[j] + bottom[j];
            dst[j] = top[j] + ((65535 - temp_sum >= 0 ? 65535 - temp_sum : temp_sum - 65535) - top[j]) * local_opacity;
        }
        dst += dst_linesize;
        top += top_linesize;
        bottom += bottom_linesize;
    }
}
