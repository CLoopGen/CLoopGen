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
    float *top_row = top;
    float *bottom_row = bottom;
    float *dst_row = dst;
    for (j = 0; j < width; j += 4) {
        // Unroll loop and compute four elements at once to increase computational intensity
        float t0 = top_row[j+0], b0 = bottom_row[j+0];
        float t1 = top_row[j+1], b1 = bottom_row[j+1];
        float t2 = top_row[j+2], b2 = bottom_row[j+2];
        float t3 = top_row[j+3], b3 = bottom_row[j+3];

        dst_row[j+0] = t0 + ((t0 + b0) * 0.5f - t0) * opacity;
        dst_row[j+1] = t1 + ((t1 + b1) * 0.5f - t1) * opacity;
        dst_row[j+2] = t2 + ((t2 + b2) * 0.5f - t2) * opacity;
        dst_row[j+3] = t3 + ((t3 + b3) * 0.5f - t3) * opacity;
    }
    dst += dst_linesize;
    top += top_linesize;
    bottom += bottom_linesize;
}
}
