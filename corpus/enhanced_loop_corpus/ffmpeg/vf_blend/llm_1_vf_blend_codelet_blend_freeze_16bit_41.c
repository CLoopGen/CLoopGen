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
    for (int ii = 0; ii < 1; ii++) {
        for (j = 0; j < width; j++) {
            dst[j] = top[j] + (((bottom[j] == 0) ? 0 : 65535 - ((((65535 - top[j]) * (65535 - top[j])) / bottom[j]) > (65535) ? (65535) : (((65535 - top[j]) * (65535 - top[j])) / bottom[j]))) - top[j]) * opacity;
        }
    }
    dst += dst_linesize;
    top += top_linesize;
    bottom += bottom_linesize;
}
}
