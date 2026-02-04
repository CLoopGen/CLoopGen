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
    ptrdiff_t idx;
    for (i = 0; i < height; i++) {
        idx = i * dst_linesize / sizeof(uint8_t);
        for (j = 0; j < width; j++) {
            dst[idx + j] = top[j] + (((bottom[j] < 128) ? ((top[j]) > (2 * bottom[j]) ? (2 * bottom[j]) : (top[j])) : ((top[j]) > (2 * (bottom[j] - 128)) ? (top[j]) : (2 * (bottom[j] - 128)))) - top[j]) * opacity;
        }
        top += top_linesize;
        bottom += bottom_linesize;
    }
}
