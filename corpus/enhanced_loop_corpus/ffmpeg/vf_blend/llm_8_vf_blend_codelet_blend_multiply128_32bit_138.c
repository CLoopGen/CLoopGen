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
    float *dst_row = dst + i * dst_linesize;
    float *top_row = top + i * top_linesize;
    float *bottom_row = bottom + i * bottom_linesize;
    for (j = 0; j < width; j += 4) {
        float t0 = top_row[j];
        float b0 = bottom_row[j];
        dst_row[j] = t0 + (((t0 - 0.5f) * b0 / 0.125f + 0.5f) - t0) * opacity;

        if (j + 1 < width) {
            float t1 = top_row[j+1];
            float b1 = bottom_row[j+1];
            dst_row[j+1] = t1 + (((t1 - 0.5f) * b1 / 0.125f + 0.5f) - t1) * opacity;
        }
        if (j + 2 < width) {
            float t2 = top_row[j+2];
            float b2 = bottom_row[j+2];
            dst_row[j+2] = t2 + (((t2 - 0.5f) * b2 / 0.125f + 0.5f) - t2) * opacity;
        }
        if (j + 3 < width) {
            float t3 = top_row[j+3];
            float b3 = bottom_row[j+3];
            dst_row[j+3] = t3 + (((t3 - 0.5f) * b3 / 0.125f + 0.5f) - t3) * opacity;
        }
    }
}
}
