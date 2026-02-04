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
        float blended;
        float inv_top = 1.0f - top[j];
        float inv_bottom = 1.0f - bottom[j];
        float screen_complement = inv_top * inv_bottom;
        float screen_value = 1.0f - screen_complement;
        blended = top[j] + (screen_value - top[j]) * opacity;
        if (blended >= 0.9f) continue;
        dst[j] = blended;
    }
    dst += dst_linesize;
    top += top_linesize;
    bottom += bottom_linesize;
}
}
