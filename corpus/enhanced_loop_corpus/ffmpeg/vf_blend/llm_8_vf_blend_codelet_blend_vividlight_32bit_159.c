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
        float top_val1 = top[j];
        float bot_val1 = bottom[j];
        float result1;
        if (top_val1 < 0.5) {
            float temp = 2.0f * top_val1;
            result1 = (temp <= 0.0f) ? temp : ((1.0f - (1.0f - bot_val1) / temp) > 0.0f ? (1.0f - (1.0f - bot_val1) / temp) : 0.0f);
        } else {
            float adjusted_top = 2.0f * (top_val1 - 0.5f);
            float denom = 1.0f - adjusted_top;
            result1 = (adjusted_top >= 1.0f) ? adjusted_top : ((bot_val1 / denom) < 1.0f ? (bot_val1 / denom) : 1.0f);
        }
        dst[j] = top_val1 + (result1 - top_val1) * opacity;

        if (i + 1 < height) {
            float top_val2 = top[top_linesize + j];
            float bot_val2 = bottom[bottom_linesize + j];
            float result2;
            if (top_val2 < 0.5) {
                float temp = 2.0f * top_val2;
                result2 = (temp <= 0.0f) ? temp : ((1.0f - (1.0f - bot_val2) / temp) > 0.0f ? (1.0f - (1.0f - bot_val2) / temp) : 0.0f);
            } else {
                float adjusted_top = 2.0f * (top_val2 - 0.5f);
                float denom = 1.0f - adjusted_top;
                result2 = (adjusted_top >= 1.0f) ? adjusted_top : ((bot_val2 / denom) < 1.0f ? (bot_val2 / denom) : 1.0f);
            }
            dst[dst_linesize + j] = top_val2 + (result2 - top_val2) * opacity;
        }
    }
    dst += 2 * dst_linesize;
    top += 2 * top_linesize;
    bottom += 2 * bottom_linesize;
}
}
