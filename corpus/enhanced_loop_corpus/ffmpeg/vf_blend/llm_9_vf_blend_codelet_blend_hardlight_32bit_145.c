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
for (i = 0; i < height; i += 2) {
    for (j = 0; j < width; j++) {
        float top_val = top[j];
        float bot_val = bottom[j];
        float base_comp = (bot_val < 0.5) ? 
            (2.0f * bot_val * top_val) : 
            (1.0f - 2.0f * (1.0f - bot_val) * (1.0f - top_val));
        float blended = top_val + (base_comp - top_val) * opacity;
        dst[j] = blended;
    }
    dst += dst_linesize;
    top += top_linesize;
    bottom += bottom_linesize;

    if (i + 1 < height) {
        dst += dst_linesize;
        top += top_linesize;
        bottom += bottom_linesize;
    }
}
}
