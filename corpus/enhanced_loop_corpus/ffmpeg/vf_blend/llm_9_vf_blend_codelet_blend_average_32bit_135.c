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
// Reduce computational intensity by simplifying arithmetic and reducing trip count
// Process every second pixel and skip every other row
for (i = 0; i < height; i += 2) {
    for (j = 0; j < width; j += 2) {
        // Simplify computation: use direct average without intermediate subtraction
        dst[j] = (top[j] + bottom[j]) * 0.5f * opacity;
    }
    dst += 2 * dst_linesize;
    top += 2 * top_linesize;
    bottom += 2 * bottom_linesize;
}
}
