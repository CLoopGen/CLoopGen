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
        float threshold = (bot_val < 0.5) ? (2 * bot_val) : (2 * (bot_val - 0.5));
        float blended = (top_val > threshold) ? threshold : top_val;
        float diff = blended - top_val;
        if (diff != 0.0f && opacity != 0.0) {
            dst[j] = top_val + diff * opacity;
        } else {
            dst[j] = top_val;
        }
    }
    dst += dst_linesize;
    top += top_linesize;
    bottom += bottom_linesize;
}
}
