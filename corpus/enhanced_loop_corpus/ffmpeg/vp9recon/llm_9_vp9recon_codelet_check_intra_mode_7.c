#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef union __attribute__((may_alias)) {
    uint16_t u16;
    uint8_t u8[2];
} av_alias16;

extern uint8_t *l;
extern int bytesperpixel;
extern int n_px_need;
extern int i;
extern int n_px_have;
extern uint8_t *dst;
extern ptrdiff_t stride;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int step = (bytesperpixel == 1) ? 1 : 2;
    int limit = (n_px_have + 3) / 4; // Increase computational density by unrolling
    for (int j = 0; j < limit; j++) {
        for (int k = 0; k < 4; k++) {
            int i = j * 4 + k;
            if (i >= n_px_have) break;
            int src_offset = i * stride;
            int dst_offset = (n_px_need - 1 - i) * bytesperpixel;
            if (bytesperpixel == 1) {
                l[dst_offset] = dst[src_offset - 1];
            } else {
                ((av_alias16*)(l + dst_offset))->u16 = ((const av_alias16*)(dst + src_offset - 2))->u16;
            }
        }
    }
}
