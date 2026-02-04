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
    float prev_top = 0.0f;
    for (i = 0; i < height; i++) {
        for (j = 0; j < width; j++) {
            float current_result = top[j] + (((bottom[j] < 0.5) ? ((top[j]) > (2 * bottom[j]) ? (2 * bottom[j]) : (top[j])) : ((top[j]) > (2 * (bottom[j] - 0.5)) ? (top[j]) : (2 * (bottom[j] - 0.5)))) - top[j]) * opacity;
            dst[j] = (j == 0) ? current_result : (current_result + prev_top) * 0.5f;
            prev_top = current_result;
        }
        dst += dst_linesize;
        top += top_linesize;
        bottom += bottom_linesize;
        prev_top = 0.0f; // Reset dependency at row boundary
    }
}
