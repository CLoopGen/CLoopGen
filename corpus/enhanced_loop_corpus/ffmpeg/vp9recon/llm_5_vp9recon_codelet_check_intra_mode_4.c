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
extern int i;
extern int n_px_have;
extern uint8_t *dst;
extern ptrdiff_t stride;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < n_px_have; i++) {
        const int offset = i * stride;
        const int src_idx = offset - 1;
        const int dst_idx = i * 2;
        if (bytesperpixel == 1) {
            l[i] = dst[src_idx];
        } else if ((((uintptr_t)&dst[src_idx]) & 1) == 0) {
            ((av_alias16 *)(l + dst_idx))->u16 = ((const av_alias16 *)(&dst[src_idx * 2 / 2]))->u16;
        }
    }
}
