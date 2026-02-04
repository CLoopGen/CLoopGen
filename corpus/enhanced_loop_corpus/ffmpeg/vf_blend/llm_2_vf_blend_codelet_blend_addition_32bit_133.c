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
    ptrdiff_t idx = i * dst_linesize / sizeof(float);
    for (j = 0; j < width; j++) {
        ptrdiff_t pos = idx + j;
        ((float*)dst)[pos] = ((float*)top)[pos] + (((float*)top)[pos] + ((float*)bottom)[pos] - ((float*)top)[pos]) * opacity;
    }
}
}
