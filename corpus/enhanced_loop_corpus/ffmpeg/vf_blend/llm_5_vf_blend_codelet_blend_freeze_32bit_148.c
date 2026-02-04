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
        float top_val = top[j];
        float bottom_val = bottom[j];
        double term = 1.0;
        if (bottom_val != 0.0 && top_val < 1.0) {
            double temp = ((1.0 - top_val) * (1.0 - top_val)) / bottom_val;
            term = (temp < 1.0) ? temp : 1.0;
        } else {
            term = (top_val >= 1.0) ? 1.0 : term;
        }
        double factor = (bottom_val == 0.0) ? 0.0 : 1.0 - term;
        dst[j] = top_val + (factor - top_val) * opacity;
    }
    dst += dst_linesize;
    top += top_linesize;
    bottom += bottom_linesize;
}
}
