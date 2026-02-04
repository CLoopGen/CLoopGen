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
        float bot_val = bottom[j];
        float top_val = top[j];
        float result;
        if (bot_val < 0.5) {
            float temp = (top_val > 2 * bot_val) ? (2 * bot_val) : top_val;
            result = top_val + (temp - top_val) * opacity;
        } else {
            float temp = (top_val > 2 * (bot_val - 0.5)) ? top_val : (2 * (bot_val - 0.5));
            result = top_val + (temp - top_val) * opacity;
        }
        dst[j] = result;
    }
    dst += dst_linesize;
    top += top_linesize;
    bottom += bottom_linesize;
}
}
