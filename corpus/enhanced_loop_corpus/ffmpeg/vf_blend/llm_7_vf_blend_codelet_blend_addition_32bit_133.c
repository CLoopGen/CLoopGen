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
    float *top_local = top;
    float *bottom_local = bottom;
    float *dst_local = dst;
    double opacity_local = opacity;
    ptrdiff_t t_ls = top_linesize;
    ptrdiff_t b_ls = bottom_linesize;
    ptrdiff_t d_ls = dst_linesize;
    ptrdiff_t w = width;
    ptrdiff_t h = height;

    for (i = 0; i < h; i++) {
        float temp_val = 0.0f;
        for (j = 0; j < w; j++) {
            temp_val = bottom_local[j] * opacity_local;
            dst_local[j] = top_local[j] + temp_val;
        }
        dst_local += d_ls;
        top_local += t_ls;
        bottom_local += b_ls;
    }
}
