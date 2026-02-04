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
        float blend = t_val + (b_val - t_val) * opacity;
        dst[j] = blend;

        if (i + 1 < height) {
            float t_val_next = *(top + top_linesize + j);
            float b_val_next = *(bottom + bottom_linesize + j);
            float blend_next = t_val_next + (b_val_next - t_val_next) * opacity;
            *(dst + dst_linesize + j) = blend_next;
        }
    }
    dst += 2 * dst_linesize;
    top += 2 * top_linesize;
    bottom += 2 * bottom_linesize;
}
}
