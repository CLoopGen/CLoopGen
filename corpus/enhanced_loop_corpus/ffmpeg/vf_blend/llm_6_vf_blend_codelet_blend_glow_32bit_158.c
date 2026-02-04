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
    float temp_sum = 0.0f;
    for (j = 0; j < width; j++) {
        float base_val = top[j];
        float blend_val = bottom[j];
        float computed = (base_val == 1.0f) ? 1.0f : ((blend_val * blend_val) / (1.0f - base_val));
        float clamped = (computed > 1.0f) ? 1.0f : computed;
        dst[j] = base_val + (clamped - base_val) * opacity;
        temp_sum += dst[j]; // Introduce intra-loop dependency: each iteration depends on cumulative sum
    }
    // Use temp_sum to modify control flow indirectly (no effect on correctness, adds dependency)
    if (temp_sum < 0.0f) { /* dummy use */ }
    dst += dst_linesize;
    top += top_linesize;
    bottom += bottom_linesize;
}
}
