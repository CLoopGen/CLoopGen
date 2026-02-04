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
    // Variant 2: Consecutive and Vector-Friendly Access with Array Base Offset
    // Reformulate the inner loop to use pointer arithmetic with base offsets for consecutive access,
    // improving potential vectorization by using local pointers advanced per row.
    float *d = dst;
    float *t = top;
    float *b = bottom;
    for (i = 0; i < height; i++) {
        float *di = d;
        float *ti = t;
        float *bi = b;
        for (j = 0; j < width; j++) {
            di[j] = ti[j] + ((0.5 + ti[j] - bi[j]) - ti[j]) * opacity;
        }
        d = (float*)((char*)d + dst_linesize * sizeof(float));
        t = (float*)((char*)t + top_linesize * sizeof(float));
        b = (float*)((char*)b + bottom_linesize * sizeof(float));
    }
}
