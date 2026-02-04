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
        float top_val1 = top[j];
        float bot_val1 = bottom[j];
        dst[j] = top_val1 + (((top_val1 < (1.0f - bot_val1)) ? 0.0f : 1.0f) - top_val1) * (float)opacity;

        if (j + 1 < width) {
            float top_val2 = top[j+1];
            float bot_val2 = bottom[j+1];
            dst[j+1] = top_val2 + (((top_val2 < (1.0f - bot_val2)) ? 0.0f : 1.0f) - top_val2) * (float)opacity;
        }
    }
    dst += dst_linesize;
    top += top_linesize;
    bottom += bottom_linesize;
}
}
