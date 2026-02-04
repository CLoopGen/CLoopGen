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
        float t = top[j];
        float b = bottom[j];
        float one_minus_b_sq = (1.0f - b) * (1.0f - b);
        float alpha;
        if (t != 0.0f) {
            float temp = one_minus_b_sq / t;
            alpha = (temp < 1.0f) ? temp : 1.0f;
        } else {
            alpha = 0.0f;
        }
        dst[j] = t + ((1.0f - alpha - t) * opacity);
    }
    dst += dst_linesize;
    top += top_linesize;
    bottom += bottom_linesize;
}
}
