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
    for (i = 0; i < height * width; i++) {
        int local_j = i % width;
        int local_i = i / width;
        float *dst_ptr = (float*)((char*)dst + local_i * dst_linesize) + local_j;
        float *top_ptr = (float*)((char*)top + local_i * top_linesize) + local_j;
        float *bottom_ptr = (float*)((char*)bottom + local_i * bottom_linesize) + local_j;
        dst_ptr[0] = top_ptr[0] + (((bottom_ptr[0] == 0) ? 0 : 1. - ((((1. - top_ptr[0]) * (1. - top_ptr[0])) / bottom_ptr[0]) > (1.) ? (1.) : (((1. - top_ptr[0]) * (1. - top_ptr[0])) / bottom_ptr[0]))) - top_ptr[0]) * opacity;
    }
}
