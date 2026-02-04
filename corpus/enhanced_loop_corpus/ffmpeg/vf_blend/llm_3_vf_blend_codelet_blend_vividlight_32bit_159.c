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
    // Use strided memory access with a fixed stride of 4 to simulate non-unit stride access pattern
    const int stride = 4;
    for (i = 0; i < height; i++) {
        for (j = 0; j < width; j += stride) {
            // Only process elements within bounds
            for (int s = 0; s < stride && (j + s) < width; s++) {
                int idx = j + s;
                dst[idx] = top[idx] + (((top[idx] < 0.5) ? (((2 * top[idx]) <= 0.) ? (2 * top[idx]) : ((0.) > (1. - (1. - (bottom[idx])) / (2 * top[idx])) ? (0.) : (1. - (1. - (bottom[idx])) / (2 * top[idx])))) : (((2 * (top[idx] - 0.5)) >= 1.) ? (2 * (top[idx] - 0.5)) : ((1.) > (((bottom[idx]) / (1. - (2 * (top[idx] - 0.5))))) ? (((bottom[idx]) / (1. - (2 * (top[idx] - 0.5))))) : (1.)))) - top[idx]) * opacity;
            }
        }
        dst += dst_linesize;
        top += top_linesize;
        bottom += bottom_linesize;
    }
}
