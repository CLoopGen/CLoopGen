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
    uint16_t *dst_row = dst;
    uint16_t *top_row = top;
    uint16_t *bottom_row = bottom;
    ptrdiff_t dls = dst_linesize;
    ptrdiff_t tls = top_linesize;
    ptrdiff_t bls = bottom_linesize;
    double op = opacity;

    for (i = 0; i < height; i++) {
        uint16_t tj, bj;
        for (j = 0; j < width; j++) {
            tj = top_row[j];
            bj = bottom_row[j];
            dst_row[j] = tj + ((1 * ((tj * bj) / 4095) - tj) * op);
        }
        dst_row += dls;
        top_row += tls;
        bottom_row += bls;
    }
}
