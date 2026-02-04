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
        uint16_t t = top[j];
        uint16_t b = bottom[j];
        int32_t scaled_diff;
        if (t < 32768) {
            int32_t twice_t = 2 * t;
            if (twice_t == 0) {
                scaled_diff = twice_t;
            } else {
                int32_t val = (65535 - b) << 16;
                int32_t div = val / twice_t;
                scaled_diff = (0 > 65535 - div) ? 0 : (65535 - div);
            }
        } else {
            int32_t adjusted = 2 * (t - 32768);
            if (adjusted == 65535) {
                scaled_diff = adjusted;
            } else {
                int32_t denom = 65535 - adjusted;
                int32_t result = (b << 16) / denom;
                scaled_diff = (65535 > result) ? result : 65535;
            }
        }
        dst[j] = t + ((scaled_diff - t) * opacity);
    }
    dst += dst_linesize;
    top += top_linesize;
    bottom += bottom_linesize;
}
}
