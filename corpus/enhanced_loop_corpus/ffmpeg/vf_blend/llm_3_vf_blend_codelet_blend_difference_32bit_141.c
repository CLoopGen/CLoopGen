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
    // Variant 2: Consecutive Block Access with Pointer Arithmetic
    // Flatten the 2D iteration into a more sequential memory access pattern
    // by treating each row as a block and using direct pointer arithmetic
    // to ensure linear traversal within the row.

    float *d = dst;
    float *t = top;
    float *b = bottom;

    for (i = 0; i < height; i++) {
        float *di = d;
        float *ti = t;
        float *bi = b;

        // Sequentially process the entire width with local pointers
        for (j = 0; j < width; j++) {
            float diff = ti[j] - bi[j];
            float abs_diff = diff >= 0 ? diff : -diff;
            di[j] = ti[j] + (abs_diff - ti[j]) * opacity;
        }

        // Update base pointers with linesizes (row strides)
        d = (float*)((char*)d + dst_linesize);
        t = (float*)((char*)t + top_linesize);
        b = (float*)((char*)b + bottom_linesize);
    }
}
