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
    // Variant 2: Consecutive Block Memory Access with Pointer Arithmetic
    // Process data using pointer variables instead of array indexing to encourage consecutive access
    // and optimize memory prefetching by eliminating index calculations
    float *d = dst;
    float *t = top;
    float *b = bottom;

    for (i = 0; i < height; i++) {
        float *d_row = d;
        float *t_row = t;
        float *b_row = b;

        for (j = 0; j < width; j++) {
            d_row[j] = t_row[j] + (((t_row[j] + b_row[j]) / 2) - t_row[j]) * opacity;
        }

        d = (float *)((char *)d + dst_linesize);
        t = (float *)((char *)t + top_linesize);
        b = (float *)((char *)b + bottom_linesize);
    }
}
