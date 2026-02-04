#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern ptrdiff_t top_linesize;
extern ptrdiff_t bottom_linesize;
extern ptrdiff_t dst_linesize;
extern ptrdiff_t width;
extern ptrdiff_t height;
extern  float *top;
extern  float *bottom;
extern float *dst;
extern double opacity;
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    float *dst_i = dst;
    float *top_i = top;
    float *bottom_i = bottom;
    ptrdiff_t dls = dst_linesize;
    ptrdiff_t tls = top_linesize;
    ptrdiff_t bls = bottom_linesize;
    float tj, bj;
    for (i = 0; i < height; i++) {
        for (j = 0; j < width; j++) {
            tj = top_i[j];
            bj = bottom_i[j];
            dst_i[j] = tj + ((tj + bj - 0.5) - tj) * opacity;
        }
        dst_i += dls;
        top_i += tls;
        bottom_i += bls;
    }
}
