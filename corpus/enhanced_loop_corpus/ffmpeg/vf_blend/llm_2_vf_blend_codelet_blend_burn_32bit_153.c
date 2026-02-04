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
    // Variant 1: Strided Memory Access Pattern
    // Instead of processing j from 0 to width sequentially, access elements with a stride of 2
    // This changes spatial locality and may affect cache behavior.
    // We process even indices first, then odd indices in a second pass within the same row.

    for (i = 0; i < height; i++) {
        // First pass: even indices
        for (j = 0; j < width; j += 2) {
            dst[j] = top[j] + (((((top[j]) <= 0.) ? (top[j]) : ((0.) > (1. - (1. - (bottom[j])) / (top[j])) ? (0.) : (1. - (1. - (bottom[j])) / (top[j]))))) - top[j]) * opacity;
        }
        // Second pass: odd indices
        for (j = 1; j < width; j += 2) {
            dst[j] = top[j] + (((((top[j]) <= 0.) ? (top[j]) : ((0.) > (1. - (1. - (bottom[j])) / (top[j])) ? (0.) : (1. - (1. - (bottom[j])) / (top[j]))))) - top[j]) * opacity;
        }
        dst += dst_linesize;
        top += top_linesize;
        bottom += bottom_linesize;
    }
}
