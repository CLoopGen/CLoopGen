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
        float result;
        if (t < 0.5) {
            float temp = 2.0f * t;
            if (temp <= 0.0f) {
                result = temp;
            } else {
                float blend = 1.0f - (1.0f - b) / temp;
                result = (blend < 0.0f) ? 0.0f : (blend > 1.0f) ? 1.0f : blend;
            }
        } else {
            float u = 2.0f * (t - 0.5f);
            if (u >= 1.0f) {
                result = u;
            } else {
                float denominator = 1.0f - u;
                float blend = (denominator == 0.0f) ? 1.0f : b / denominator;
                result = (blend > 1.0f) ? 1.0f : blend;
            }
        }
        dst[j] = t + (result - t) * opacity;
    }
    dst += dst_linesize;
    top += top_linesize;
    bottom += bottom_linesize;
}
}
