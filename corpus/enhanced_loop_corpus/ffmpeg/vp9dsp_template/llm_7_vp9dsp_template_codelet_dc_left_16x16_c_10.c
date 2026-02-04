#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef union __attribute__((may_alias)) {
    uint32_t u32;
    uint16_t u16[2];
    uint8_t u8[4];
    float f32;
} av_alias32;

extern ptrdiff_t stride;
extern uint8_t *dst;
extern uint32_t dc;
extern int y;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    uint8_t *local_dst = dst;
    uint32_t local_dc = dc;
    ptrdiff_t local_stride = stride;
    for (y = 0; y < 16; y++) {
        ((av_alias32 *)(local_dst + 0))->u32 = local_dc;
        ((av_alias32 *)(local_dst + 4))->u32 = local_dc;
        ((av_alias32 *)(local_dst + 8))->u32 = local_dc;
        ((av_alias32 *)(local_dst + 12))->u32 = local_dc;
        // Eliminate loop-carried dependency on shared 'dst' by using local pointer updated only at loop level
        local_dst += local_stride;
    }
    // No write-back to global dst; assumes dst is not used after loop (or is read-only in context)
}
