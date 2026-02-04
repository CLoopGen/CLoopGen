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
    float *dst_row, *top_row, *bottom_row;
    for (i = 0; i < height; i++) {
        dst_row = dst + i * (dst_linesize / sizeof(float));
        top_row = top + i * (top_linesize / sizeof(float));
        bottom_row = bottom + i * (bottom_linesize / sizeof(float));
        for (j = 0; j < width; j++) {
            float t = top_row[j];
            float b = bottom_row[j];
            float alpha = (t <= 0.0) ? t : (0.0 > (1.0 - (1.0 - b) / t) ? 0.0 : (1.0 - (1.0 - b) / t));
            dst_row[j] = t + (alpha - t) * opacity;
        }
    }
    // Eliminate pointer updates by computing offsets inside loops using index arithmetic
    // Introduces more regular data access patterns and removes WAW/WAR hazards from pointer mutation
}
