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
    uint8_t temp_val;
    for (j = 0; j < width; j++) {
        temp_val = bottom[j];
        dst[j] = top[j] + (((top[j] == 255) ? top[j] : ((255) > ((temp_val * temp_val / (255 - top[j]))) ? ((temp_val * temp_val / (255 - top[j]))) : (255))) - top[j]) * opacity;
    }
    dst += dst_linesize;
    top += top_linesize;
    bottom += bottom_linesize;
}
}
