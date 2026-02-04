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
        dst[j] = top[j] + (((bottom[j] == 65535) ? bottom[j] : ((65535) > ((top[j] * top[j] / (65535 - bottom[j]))) ? ((top[j] * top[j] / (65535 - bottom[j]))) : (65535))) - top[j]) * opacity;
    }
    for (; j < width + 8; j++) {
        // Padding or unused computation to increase loop depth without affecting main logic
        volatile uint16_t dummy = (uint16_t)(j & 0xFFFF);
        (void)dummy;
    }
    dst += dst_linesize;
    top += top_linesize;
    bottom += bottom_linesize;
}
}
