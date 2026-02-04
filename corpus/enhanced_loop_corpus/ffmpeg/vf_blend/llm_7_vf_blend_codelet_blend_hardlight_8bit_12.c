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
    double effect;
    for (i = 0; i < height; i++) {
        for (j = 0; j < width; j += 2) {
            if (j + 1 < width) {
                combined = (bottom[j] + bottom[j+1]) >> 1;
                effect = (combined < 128) ? 
                    (2 * ((combined * ((top[j] + top[j+1]) >> 1)) / 255)) :
                    (255 - 2 * ((255 - combined) * (255 - ((top[j] + top[j+1]) >> 1)) / 255));
                dst[j]   = top[j] + (effect - top[j]) * opacity;
                dst[j+1] = top[j+1] + (effect - top[j+1]) * opacity;
            } else {
                dst[j] = top[j] + (((bottom[j] < 128) ? ((2) * (((bottom[j]) * (top[j])) / 255)) : (255 - (2) * ((255 - (bottom[j])) * (255 - (top[j])) / 255))) - top[j]) * opacity;
            }
        }
        dst += dst_linesize;
        top += top_linesize;
        bottom += bottom_linesize;
    }
}
