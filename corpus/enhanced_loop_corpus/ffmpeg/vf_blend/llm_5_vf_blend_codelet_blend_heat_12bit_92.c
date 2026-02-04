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
    for (j = 0; j < width; j++) {
        if (top[j] != 0) {
            uint32_t temp = (4095 - bottom[j]);
            temp = (temp * temp) / top[j];
            if (temp < 4095) {
                dst[j] = top[j] + (4095 - temp - top[j]) * opacity;
            } else {
                dst[j] = top[j] + (4095 - 4095 - top[j]) * opacity;
            }
        } else {
            dst[j] = top[j];
        }
    }
    dst += dst_linesize;
    top += top_linesize;
    bottom += bottom_linesize;
}
}
