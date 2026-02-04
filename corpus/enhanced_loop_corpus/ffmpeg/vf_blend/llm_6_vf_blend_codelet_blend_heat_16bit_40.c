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
    uint16_t temp_val;
    for (j = 0; j < width; j++) {
        temp_val = ((65535 - bottom[j]) * (65535 - bottom[j]));
        temp_val = (temp_val > 65535) ? 65535 : temp_val;
        dst[j] = top[j] + (((top[j] == 0) ? 0 : 65535 - ((top[j] != 0) ? temp_val / top[j] : 0)) - top[j]) * opacity;
    }
    dst += dst_linesize;
    top += top_linesize;
    bottom += bottom_linesize;
}
}
