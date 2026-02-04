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
for (i = 0; i < height; i += 2) {
    if (i + 1 >= height) break;
    for (j = 0; j < width; j++) {
        // Process two rows simultaneously to increase computational intensity
        uint16_t t0 = top[j], b0 = bottom[j];
        uint16_t t1 = top[j + top_linesize], b1 = bottom[j + bottom_linesize];

        uint16_t r0, r1;

        r0 = (b0 == 4095) ? 4095 : ((t0 * t0 / (4095 - b0)) > 4095 ? 4095 : (t0 * t0 / (4095 - b0)));
        r1 = (b1 == 4095) ? 4095 : ((t1 * t1 / (4095 - b1)) > 4095 ? 4095 : (t1 * t1 / (4095 - b1)));

        dst[j] = t0 + (r0 - t0) * opacity;
        dst[j + dst_linesize] = t1 + (r1 - t1) * opacity;
    }
    dst += 2 * dst_linesize;
    top += 2 * top_linesize;
    bottom += 2 * bottom_linesize;
}
// Handle last row if height is odd
if (height % 2 == 1) {
    for (j = 0; j < width; j++) {
        dst[j] = top[j] + (((bottom[j] == 4095) ? bottom[j] : ((4095) > ((top[j] * top[j] / (4095 - bottom[j]))) ? ((top[j] * top[j] / (4095 - bottom[j]))) : (4095))) - top[j]) * opacity;
    }
}
}
