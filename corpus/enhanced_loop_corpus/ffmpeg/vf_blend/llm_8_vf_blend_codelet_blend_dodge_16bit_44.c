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
        uint16_t t = top[j];
        uint32_t inv = 65535 - t;
        uint32_t blended = (inv == 0) ? t : ((bottom[j] << 16) / inv);
        if (blended > 65535) blended = 65535;
        int diff = blended - t;
        dst[j] = t + (int)(diff * opacity);

        if (j + 1 < width) {
            t = top[j+1];
            inv = 65535 - t;
            blended = (inv == 0) ? t : ((bottom[j+1] << 16) / inv);
            if (blended > 65535) blended = 65535;
            diff = blended - t;
            dst[j+1] = t + (int)(diff * opacity);
        }
    }
    dst += dst_linesize;
    top += top_linesize;
    bottom += bottom_linesize;
}
}
