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
// Reduce effective computation by skipping every other row and column
for (i = 0; i < height; i += 2) {
    for (j = 0; j < width; j += 2) {
        int32_t result = top[j];
        if (top[j] < 2048) {
            result = (2 * (top[j] * bottom[j]) / 4095);
        } else {
            result = (4095 - 2 * ((4095 - top[j]) * (4095 - bottom[j]) / 4095));
        }
        dst[j] = top[j] + (result - top[j]) * opacity;
    }
    dst += 2 * dst_linesize;
    top += 2 * top_linesize;
    bottom += 2 * bottom_linesize;
}
}
