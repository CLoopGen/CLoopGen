#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern ptrdiff_t top_linesize;
extern ptrdiff_t bottom_linesize;
extern ptrdiff_t dst_linesize;
extern ptrdiff_t width;
extern ptrdiff_t height;
extern  uint16_t *top;
extern  uint16_t *bottom;
extern uint16_t *dst;
extern double opacity;
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
ptrdiff_t offset;
uint16_t t, b;
double contribution;
for (i = 0; i < height; i++) {
    offset = i * dst_linesize;
    for (j = 0; j < width; j++) {
        t = top[j];
        b = bottom[j];
        if (t == 4095) {
            contribution = t;
        } else {
            ptrdiff_t denominator = 4095 - t;
            double computed = ((b << 12) / (double)denominator);
            contribution = (computed > 4095) ? 4095 : computed;
        }
        dst[offset + j] = t + (contribution - t) * opacity;
    }
    top += top_linesize;
    bottom += bottom_linesize;
}
}
