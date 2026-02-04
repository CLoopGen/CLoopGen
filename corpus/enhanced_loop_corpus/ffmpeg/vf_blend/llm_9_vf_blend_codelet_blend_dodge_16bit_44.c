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
    for (j = 0; j < width; j++) {
        uint16_t t0 = top[j];
        uint16_t b0 = bottom[j];
        uint32_t inv0 = 65535 - t0;
        uint32_t blended0 = (t0 == 65535) ? 65535 : ((b0 << 16) / (inv0 ? inv0 : 1));
        if (blended0 > 65535) blended0 = 65535;
        dst[j] = t0 + (int)(((blended0 - t0) * opacity));

        if (i + 1 < height) {
            uint16_t t1 = (top + top_linesize)[j];
            uint16_t b1 = (bottom + bottom_linesize)[j];
            uint32_t inv1 = 65535 - t1;
            uint32_t blended1 = (t1 == 65535) ? 65535 : ((b1 << 16) / (inv1 ? inv1 : 1));
            if (blended1 > 65535) blended1 = 65535;
            (dst + dst_linesize)[j] = t1 + (int)(((blended1 - t1) * opacity));
        }
    }
    dst += 2 * dst_linesize;
    top += 2 * top_linesize;
    bottom += 2 * bottom_linesize;
}
}
