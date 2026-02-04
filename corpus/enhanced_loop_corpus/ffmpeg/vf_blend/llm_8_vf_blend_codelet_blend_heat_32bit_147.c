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
        float inv_bot_sq = (1.0f - bot_val) * (1.0f - bot_val);
        float ratio = (top_val == 0.0f) ? 0.0f : inv_bot_sq / top_val;
        float blend_factor = (ratio > 1.0f) ? 1.0f : ratio;
        float result = top_val + ((blend_factor - top_val) * opacity);
        dst[j] = result;
    }
    if (i + 1 < height) {
        float *dst_next = dst + dst_linesize;
        float *top_next = top + top_linesize;
        float *bot_next = bottom + bottom_linesize;
        for (j = 0; j < width; j++) {
            float top_val = top_next[j];
            float bot_val = bot_next[j];
            float inv_bot_sq = (1.0f - bot_val) * (1.0f - bot_val);
            float ratio = (top_val == 0.0f) ? 0.0f : inv_bot_sq / top_val;
            float blend_factor = (ratio > 1.0f) ? 1.0f : ratio;
            float result = top_val + ((blend_factor - top_val) * opacity);
            dst_next[j] = result;
        }
        dst += 2 * dst_linesize;
        top += 2 * top_linesize;
        bottom += 2 * bottom_linesize;
    } else {
        dst += dst_linesize;
        top += top_linesize;
        bottom += bottom_linesize;
    }
}
}
