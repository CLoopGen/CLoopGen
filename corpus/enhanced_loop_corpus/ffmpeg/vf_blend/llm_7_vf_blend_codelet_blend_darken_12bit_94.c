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
    uint16_t *dst_i = dst;
    uint16_t *top_i = top;
    uint16_t *bottom_i = bottom;
    ptrdiff_t tls = top_linesize;
    ptrdiff_t bls = bottom_linesize;
    ptrdiff_t dls = dst_linesize;
    int w = width;
    double op = opacity;

    for (i = 0; i < height; i++) {
        for (j = 0; j < w; j++) {
            uint16_t min_val = top_i[j];
            if (bottom_i[j] < min_val) {
                min_val = bottom_i[j];
            }
            dst_i[j] = top_i[j] + (min_val - top_i[j]) * op;
        }
        dst_i += dls;
        top_i += tls;
        bottom_i += bls;
    }
}
