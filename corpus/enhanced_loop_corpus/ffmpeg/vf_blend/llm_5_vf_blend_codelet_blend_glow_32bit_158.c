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

        if (t < 0.999f) {
            float computed = b * b / (1.0f - t);
            float clamped = computed;
            if (computed > 1.0f) {
                clamped = 1.0f;
            }
            dst[j] = t + (clamped - t) * opacity;
        } else {
            dst[j] = t; // When top is nearly 1, output equals top regardless of opacity blending
        }
    }
    dst += dst_linesize;
    top += top_linesize;
    bottom += bottom_linesize;
}
}
