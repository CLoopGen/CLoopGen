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
extern uint8_t *dst;
extern ptrdiff_t stride;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access with reverse copy order
    // Instead of accessing l and dst in a strided or negative index pattern,
    // we rewrite the loop to traverse dst consecutively backwards and write to l consecutively.
    uint8_t *dst_end = &dst[(n_px_need - 1) * stride];
    if (bytesperpixel == 1) {
        for (i = 0; i < n_px_need; i++) {
            l[i] = dst_end[-i * stride];
        }
    } else {
        av_alias16 *l16 = (av_alias16*)l;
        const av_alias16 *src16;
        for (i = 0; i < n_px_need; i++) {
            src16 = (const av_alias16*)&dst_end[-i * stride];
            l16[i].u16 = src16->u16;
        }
    }
}
