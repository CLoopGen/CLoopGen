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
    double op = opacity;
    int w = (int)width;
    int h = (int)height;

    for (i = 0; i < h; i++) {
        float *d = dst_i;
        float *t = top_i;
        float *b = bottom_i;
        for (j = 0; j < w; j++) {
            d[j] = t[j] + (((b[j] < 0.5) ? ((2) * ((b[j] * t[j]) / 1.)) : (1. - (2) * ((1. - b[j]) * (1. - t[j]) / 1.))) - t[j]) * op;
        }
        dst_i += dls;
        top_i += tls;
        bottom_i += bls;
    }
    dst = dst_i;
    top = top_i;
    bottom = bottom_i;
}
