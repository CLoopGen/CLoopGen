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
        float top_cur = top[j];
        float bot_cur = bottom[j];
        float base = (top_cur >= 1.0f) ? top_cur : ((bot_cur / (1.0f - top_cur)) > 1.0f ? (bot_cur / (1.0f - top_cur)) : 1.0f);
        dst[j] = top_cur + (base - top_cur) * opacity;

        if (i + 1 < height) {
            float *top_next = top + top_linesize;
            float *bottom_next = bottom + bottom_linesize;
            float *dst_next = dst + dst_linesize;
            float top_cur_n = top_next[j];
            float bot_cur_n = bottom_next[j];
            float base_n = (top_cur_n >= 1.0f) ? top_cur_n : ((bot_cur_n / (1.0f - top_cur_n)) > 1.0f ? (bot_cur_n / (1.0f - top_cur_n)) : 1.0f);
            dst_next[j] = top_cur_n + (base_n - top_cur_n) * opacity;
        }
    }
    dst += 2 * dst_linesize;
    top += 2 * top_linesize;
    bottom += 2 * bottom_linesize;
}
}
