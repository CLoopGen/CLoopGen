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
    float prev_top_j = 0.0f;
    for (i = 0; i < height; i++) {
        for (j = 0; j < width; j++) {
            float current_top = top[j];
            float safe_bottom = (bottom[j] == 1.) ? 1.0f : ((1.0) > (current_top * current_top / (1.0 - bottom[j])) ? (current_top * current_top / (1.0 - bottom[j])) : 1.0);
            float blended = current_top + (safe_bottom - current_top) * opacity;
            dst[j] = blended + (j > 0 ? (dst[j-1] - prev_top_j) * 0.1 : 0); // Introduce RAW and WAW dependency: dst[j] depends on dst[j-1]
            prev_top_j = current_top;
        }
        dst += dst_linesize;
        top += top_linesize;
        bottom += bottom_linesize;
    }
}
