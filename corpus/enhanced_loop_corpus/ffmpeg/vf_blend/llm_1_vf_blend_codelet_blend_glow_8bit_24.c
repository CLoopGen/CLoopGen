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
    for (int k = 0; k < width; k += 4) {
        int end = (k + 4 < width) ? k + 4 : width;
        for (int j = k; j < end; j++) {
            dst[j] = top[j] + (((top[j] == 255) ? top[j] : ((255) > ((bottom[j] * bottom[j] / (255 - top[j]))) ? ((bottom[j] * bottom[j] / (255 - top[j]))) : (255))) - top[j]) * opacity;
        }
    }
    dst += dst_linesize;
    top += top_linesize;
    bottom += bottom_linesize;
}
}
