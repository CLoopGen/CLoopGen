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
        float t = top[j];
        float b = bottom[j];
        float one_minus_t = 1.0 - t;
        float adjusted = 1.0;

        if (t < 1.0 && one_minus_t > 0.0) {
            double temp_ratio = (double)b / one_minus_t;
            if (temp_ratio < 1.0) {
                adjusted = (float)temp_ratio;
            }
        } else {
            adjusted = t;
        }

        dst[j] = t + (adjusted - t) * opacity;
    }
    dst += dst_linesize;
    top += top_linesize;
    bottom += bottom_linesize;
}
}
