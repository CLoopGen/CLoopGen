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
    uint8_t combined;
    uint8_t blended;
    for (i = 0; i < height; i++) {
        for (j = 0; j < width; j += 2) {
            if (j + 1 < width) {
                combined = (top[j] + bottom[j] > 255) ? 255 : top[j] + bottom[j];
                blended = top[j] + (combined - top[j]) * opacity;
                dst[j] = blended;

                combined = (top[j+1] + bottom[j+1] > 255) ? 255 : top[j+1] + bottom[j+1];
                blended = top[j+1] + (combined - top[j+1]) * opacity;
                dst[j+1] = blended;
            } else {
                combined = (top[j] + bottom[j] > 255) ? 255 : top[j] + bottom[j];
                dst[j] = top[j] + (combined - top[j]) * opacity;
            }
        }
        dst += dst_linesize;
        top += top_linesize;
        bottom += bottom_linesize;
    }
}
