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
    float sum, diff;
    for (i = 0; i < height; i++) {
        sum = 0.0f;
        diff = 0.0f;
        for (j = 0; j < width; j++) {
            sum = top[j] + bottom[j];
            diff = sum * 0.5f - top[j];
            dst[j] = top[j] + diff * opacity;
        }
        dst += dst_linesize;
        top += top_linesize;
        bottom += bottom_linesize;
    }
}
