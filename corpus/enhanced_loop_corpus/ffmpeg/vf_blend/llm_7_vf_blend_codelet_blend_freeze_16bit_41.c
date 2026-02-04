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
uint16_t prev_top_j = 0;
for (i = 0; i < height; i++) {
    for (j = 0; j < width; j++) {
        uint16_t current_top = top[j];
        uint16_t safe_denom = bottom[j] ? bottom[j] : 1;
        uint16_t blended = (bottom[j] == 0) ? 0 : 65535 - (((65535 - current_top) * (65535 - prev_top_j)) / safe_denom);
        if (blended > 65535) blended = 65535;
        dst[j] = current_top + ((blended - current_top) * opacity);
        prev_top_j = current_top;
    }
    dst += dst_linesize;
    top += top_linesize;
    bottom += bottom_linesize;
}
}
