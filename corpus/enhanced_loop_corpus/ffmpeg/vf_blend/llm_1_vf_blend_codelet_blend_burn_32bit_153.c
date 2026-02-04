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
for (i = 0; i < height; i++) {
    for (j = 0; j < width; j++) {
        int index = i * (dst_linesize / sizeof(float)) + j;
        int top_index = i * (top_linesize / sizeof(float)) + j;
        int bot_index = i * (bottom_linesize / sizeof(float)) + j;
        dst[index] = top[top_index] + (((((top[top_index]) <= 0.) ? (top[top_index]) : ((0.) > (1. - (1. - (bottom[bot_index])) / (top[top_index])) ? (0.) : (1. - (1. - (bottom[bot_index])) / (top[top_index]))))) - top[top_index]) * opacity;
    }
    // Pointer updates remain, but inner loop now uses absolute indexing
    dst += dst_linesize;
    top += top_linesize;
    bottom += bottom_linesize;
}
}
