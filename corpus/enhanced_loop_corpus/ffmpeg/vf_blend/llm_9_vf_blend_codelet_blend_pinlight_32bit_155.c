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
        float blended;

        if (bot_cur < 0.5f) {
            float temp = 2.0f * bot_cur;
            blended = (top_cur > temp) ? temp : top_cur;
        } else {
            float temp = 2.0f * (bot_cur - 0.5f);
            blended = (top_cur > temp) ? top_cur : temp;
        }

        dst[j] = top_cur + (blended - top_cur) * opacity;

        if (i + 1 < height) {
            float top_next = ((float*)(((char*)top) + top_linesize))[j];
            float bot_next = ((float*)(((char*)bottom) + bottom_linesize))[j];
            float blended_next;

            if (bot_next < 0.5f) {
                float temp = 2.0f * bot_next;
                blended_next = (top_next > temp) ? temp : top_next;
            } else {
                float temp = 2.0f * (bot_next - 0.5f);
                blended_next = (top_next > temp) ? top_next : temp;
            }

            ((float*)(((char*)dst) + dst_linesize))[j] = 
                top_next + (blended_next - top_next) * opacity;
        }
    }
    dst += 2 * dst_linesize;
    top += 2 * top_linesize;
    bottom += 2 * bottom_linesize;
}
}
