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
    float *dst_ptr = dst;
    float *top_ptr = top;
    float *bottom_ptr = bottom;
    for (j = 0; j < width - 3; j += 4) {
        float top_val0 = top_ptr[j+0], top_val1 = top_ptr[j+1], top_val2 = top_ptr[j+2], top_val3 = top_ptr[j+3];
        float bot_val0 = bottom_ptr[j+0], bot_val1 = bottom_ptr[j+1], bot_val2 = bottom_ptr[j+2], bot_val3 = bottom_ptr[j+3];

        float opac = (float)opacity;

        float ratio0 = (top_val0 <= 0.0f) ? top_val0 : ((1.0f - (1.0f - bot_val0) / top_val0) > 1.0f ? 1.0f : (1.0f - (1.0f - bot_val0) / top_val0));
        float ratio1 = (top_val1 <= 0.0f) ? top_val1 : ((1.0f - (1.0f - bot_val1) / top_val1) > 1.0f ? 1.0f : (1.0f - (1.0f - bot_val1) / top_val1));
        float ratio2 = (top_val2 <= 0.0f) ? top_val2 : ((1.0f - (1.0f - bot_val2) / top_val2) > 1.0f ? 1.0f : (1.0f - (1.0f - bot_val2) / top_val2));
        float ratio3 = (top_val3 <= 0.0f) ? top_val3 : ((1.0f - (1.0f - bot_val3) / top_val3) > 1.0f ? 1.0f : (1.0f - (1.0f - bot_val3) / top_val3));

        dst_ptr[j+0] = top_val0 + (ratio0 - top_val0) * opac;
        dst_ptr[j+1] = top_val1 + (ratio1 - top_val1) * opac;
        dst_ptr[j+2] = top_val2 + (ratio2 - top_val2) * opac;
        dst_ptr[j+3] = top_val3 + (ratio3 - top_val3) * opac;
    }
    // Handle remaining elements
    for (; j < width; j++) {
        dst[j] = top[j] + (((((top[j]) <= 0.) ? (top[j]) : ((0.) > (1. - (1. - (bottom[j])) / (top[j])) ? (0.) : (1. - (1. - (bottom[j])) / (top[j]))))) - top[j]) * opacity;
    }
    dst += dst_linesize;
    top += top_linesize;
    bottom += bottom_linesize;
}
}
