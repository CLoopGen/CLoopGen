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
    for (j = 0; j < width; j += 2) {
        uint16_t temp1 = (top[j] == 0) ? 0 : (((65535 - bottom[j]) * (65535 - bottom[j])) / top[j]);
        uint16_t clamped1 = (temp1 > 65535) ? 65535 : temp1;
        dst[j] = top[j] + ((clamped1 - top[j]) * opacity);

        if (j + 1 < width) {
            uint16_t temp2 = (top[j+1] == 0) ? 0 : (((65535 - bottom[j+1]) * (65535 - bottom[j+1])) / top[j+1]);
            uint16_t clamped2 = (temp2 > 65535) ? 65535 : temp2;
            dst[j+1] = top[j+1] + ((clamped2 - top[j+1]) * opacity);
        }
    }
    dst += dst_linesize;
    top += top_linesize;
    bottom += bottom_linesize;
}
}
