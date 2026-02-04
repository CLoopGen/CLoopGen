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
    ptrdiff_t dst_offset1 = 0, dst_offset2 = dst_linesize;
    ptrdiff_t top_offset1 = 0, top_offset2 = top_linesize;
    ptrdiff_t bot_offset1 = 0, bot_offset2 = bottom_linesize;

    for (j = 0; j < width; j++) {
        float top1 = top[top_offset1 + j];
        float bot1 = bottom[bot_offset1 + j];
        float base_result1 = (top1 == 1.0f) ? top1 : ((bot1 * bot1) / (1.0f - top1));
        float clamped_result1 = (base_result1 > 1.0f) ? 1.0f : base_result1;
        dst[dst_offset1 + j] = top1 + (clamped_result1 - top1) * opacity;

        if (i + 1 < height) {
            float top2 = top[top_offset2 + j];
            float bot2 = bottom[bot_offset2 + j];
            float base_result2 = (top2 == 1.0f) ? top2 : ((bot2 * bot2) / (1.0f - top2));
            float clamped_result2 = (base_result2 > 1.0f) ? 1.0f : base_result2;
            dst[dst_offset2 + j] = top2 + (clamped_result2 - top2) * opacity;
        }
    }

    dst += 2 * dst_linesize;
    top += 2 * top_linesize;
    bottom += 2 * bottom_linesize;
}
}
