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
    ptrdiff_t dst_offset = dst_linesize;
    ptrdiff_t top_offset = top_linesize;
    ptrdiff_t bot_offset = bottom_linesize;

    for (j = 0; j < width; j++) {
        uint16_t top_cur = top[j];
        uint16_t bot_cur = bottom[j];
        uint32_t mixed = (top_cur < 32768) ?
            (2ULL * top_cur * bot_cur + 65534) / 65535 :
            (65535 - (2ULL * (65535 - top_cur) * (65535 - bot_cur) + 65534) / 65535);

        int32_t delta = mixed - top_cur;
        dst[j] = top_cur + (uint16_t)(delta * opacity);

        if (i + 1 < height) {
            uint16_t top_next = top[dst_offset + j];
            uint16_t bot_next = bottom[bot_offset + j];
            uint32_t mixed_next = (top_next < 32768) ?
                (2ULL * top_next * bot_next + 65534) / 65535 :
                (65535 - (2ULL * (65535 - top_next) * (65535 - bot_next) + 65534) / 65535);

            int32_t delta_next = mixed_next - top_next;
            dst[dst_offset + j] = top_next + (uint16_t)(delta_next * opacity);
        }
    }

    dst += 2 * dst_linesize;
    top += 2 * top_linesize;
    bottom += 2 * bottom_linesize;
}
}
