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
extern  double opacity;
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < height; i++) {
    for (j = 0; j < width; j++) {
        double t_val = (double)top[j];
        double b_val = (double)bottom[j];
        double result = t_val * opacity + b_val * (1.0 - opacity) + 0.5;
        dst[j] = (uint16_t)result;
    }
    dst += dst_linesize / sizeof(uint16_t);
    top += top_linesize / sizeof(uint16_t);
    bottom += bottom_linesize / sizeof(uint16_t);
}
}
