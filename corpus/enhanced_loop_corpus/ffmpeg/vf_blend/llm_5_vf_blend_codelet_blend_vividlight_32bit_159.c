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
        float base, result;

        // Eliminate nested ternary by precomputing conditions and using early logic grouping
        if (t < 0.5f && 2.0f * t > 0.0f) {
            float inv = (1.0f - b) / (2.0f * t);
            result = (inv >= 1.0f) ? 0.0f : 1.0f - inv;
        } else if (t >= 0.5f && 2.0f * (t - 0.5f) < 1.0f) {
            float denom = 1.0f - 2.0f * (t - 0.5f);
            result = (denom <= 0.0f || b >= denom) ? 1.0f : b / denom;
        } else {
            result = 2.0f * (t < 0.5f ? t : t - 0.5f);
        }

        // Clamp result to [0,1] range to replace conditional bounds checking
        result = result < 0.0f ? 0.0f : (result > 1.0f ? 1.0f : result);
        dst[j] = t + (result - t) * opacity;
    }
    dst += dst_linesize;
    top += top_linesize;
    bottom += bottom_linesize;
}
}
