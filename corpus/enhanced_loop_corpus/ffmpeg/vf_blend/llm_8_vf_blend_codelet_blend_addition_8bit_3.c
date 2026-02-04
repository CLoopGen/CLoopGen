#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint8_t *top;
extern ptrdiff_t top_linesize;
extern  uint8_t *bottom;
extern ptrdiff_t bottom_linesize;
extern uint8_t *dst;
extern ptrdiff_t dst_linesize;
extern ptrdiff_t width;
extern ptrdiff_t height;
extern double opacity;
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < height; i++) {
    for (j = 0; j < width; j += 2) {
        int sum1 = top[j] + bottom[j];
        int clamped1 = (sum1 > 255) ? 255 : sum1;
        dst[j] = top[j] + (clamped1 - top[j]) * opacity;
        
        if (j + 1 < width) {
            int sum2 = top[j+1] + bottom[j+1];
            int clamped2 = (sum2 > 255) ? 255 : sum2;
            dst[j+1] = top[j+1] + (clamped2 - top[j+1]) * opacity;
        }
    }
    dst += dst_linesize;
    top += top_linesize;
    bottom += bottom_linesize;
}
}
