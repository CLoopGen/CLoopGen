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
    ptrdiff_t offset = i * width;
    for (j = 0; j < width; j += 2) {
        float top_val1 = top[j];
        float bot_val1 = bottom[j];
        float result1;
        if (bot_val1 < 0.5) {
            result1 = (top_val1 > (2.0f * bot_val1)) ? (2.0f * bot_val1) : top_val1;
        } else {
            result1 = (top_val1 > (2.0f * (bot_val1 - 0.5f))) ? top_val1 : (2.0f * (bot_val1 - 0.5f));
        }
        dst[j] = top_val1 + (result1 - top_val1) * opacity;

        if (j + 1 < width) {
            float top_val2 = top[j+1];
            float bot_val2 = bottom[j+1];
            float result2;
            if (bot_val2 < 0.5) {
                result2 = (top_val2 > (2.0f * bot_val2)) ? (2.0f * bot_val2) : top_val2;
            } else {
                result2 = (top_val2 > (2.0f * (bot_val2 - 0.5f))) ? top_val2 : (2.0f * (bot_val2 - 0.5f));
            }
            dst[j+1] = top_val2 + (result2 - top_val2) * opacity;
        }
    }
    dst += dst_linesize;
    top += top_linesize;
    bottom += bottom_linesize;
}
}
