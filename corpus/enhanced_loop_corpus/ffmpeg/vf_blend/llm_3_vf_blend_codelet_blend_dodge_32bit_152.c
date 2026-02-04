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
    // Variant 2: Consecutive (Blocked/Chunked) Memory Access Pattern
    const ptrdiff_t chunk_size = 4;
    for (i = 0; i < height; i++) {
        for (j = 0; j < width; j += chunk_size) {
            // Process four elements consecutively per iteration to improve cache locality
            for (ptrdiff_t k = j; k < j + chunk_size && k < width; k++) {
                dst[k] = top[k] + (((((top[k]) >= 1.) ? (top[k]) : ((1.) > (((bottom[k]) / (1. - (top[k])))) ? (((bottom[k]) / (1. - (top[k])))) : (1.)))) - top[k]) * opacity;
            }
        }
        dst += dst_linesize;
        top += top_linesize;
        bottom += bottom_linesize;
    }
}
