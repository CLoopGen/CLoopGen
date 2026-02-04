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
    for (j = 0; j < width; j += 2) {
        float t_val1 = top[j];
        float b_val1 = bottom[j];
        dst[j] = t_val1 + (b_val1 - t_val1) * opacity;
        
        if (j + 1 < width) {
            float t_val2 = top[j+1];
            float b_val2 = bottom[j+1];
            dst[j+1] = t_val2 + (b_val2 - t_val2) * opacity;
        }
    }
    dst += dst_linesize;
    top += top_linesize;
    bottom += bottom_linesize;
}
}
