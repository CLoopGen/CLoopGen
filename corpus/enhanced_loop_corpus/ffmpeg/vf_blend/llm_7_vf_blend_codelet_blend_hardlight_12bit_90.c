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
    for (i = 0; i < height; i++) {
        uint16_t combined;
        for (j = 0; j < width; j += 2) {
            if (j + 1 < width) {
                // Introduce WAW and RAW dependencies by reusing intermediate values across two elements
                combined = (top[j] + top[j+1] + bottom[j] + bottom[j+1]) >> 2;
                dst[j]   = top[j] + (((bottom[j] < 2048) ? 
                            ((2) * ((bottom[j] * top[j]) / 4095)) : 
                            (4095 - (2) * ((4095 - bottom[j]) * (4095 - top[j]) / 4095))) - top[j]) * opacity;
                dst[j+1] = top[j+1] + (((bottom[j+1] < 2048) ? 
                            ((2) * ((bottom[j+1] * top[j+1]) / 4095)) : 
                            (4095 - (2) * ((4095 - bottom[j+1]) * (4095 - top[j+1]) / 4095))) - top[j+1]) * opacity;
                // Artificially create a dependency: dst[j+1] influenced by combined value from previous computation
                dst[j+1] = (dst[j+1] + combined) >> 1;
            } else {
                dst[j] = top[j] + (((bottom[j] < 2048) ? 
                            ((2) * ((bottom[j] * top[j]) / 4095)) : 
                            (4095 - (2) * ((4095 - bottom[j]) * (4095 - top[j]) / 4095))) - top[j]) * opacity;
            }
        }
        dst += dst_linesize;
        top += top_linesize;
        bottom += bottom_linesize;
    }
}
