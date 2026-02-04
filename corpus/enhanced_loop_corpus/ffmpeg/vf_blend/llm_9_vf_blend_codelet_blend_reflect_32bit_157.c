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
        float t_val = top[j];
        float b_val = bottom[j];
        float compute_val;

        if (b_val >= 0.999f) {
            compute_val = t_val;
        } else {
            float temp = t_val * t_val;
            float div = (1.0f - b_val);
            float candidate = temp / div;
            compute_val = (candidate < 1.0f) ? candidate : 1.0f;
        }

        dst[j] = t_val + (compute_val - t_val) * opacity;

        if (i + 1 < height) {
            float t_next = top[top_linesize + j];
            float b_next = bottom[bottom_linesize + j];
            float compute_next;

            if (b_next >= 0.999f) {
                compute_next = t_next;
            } else {
                float temp_next = t_next * t_next;
                float div_next = (1.0f - b_next);
                float candidate_next = temp_next / div_next;
                compute_next = (candidate_next < 1.0f) ? candidate_next : 1.0f;
            }

            dst[dst_linesize + j] = t_next + (compute_next - t_next) * opacity;
        }
    }
    dst += 2 * dst_linesize;
    top += 2 * top_linesize;
    bottom += 2 * bottom_linesize;
}
}
