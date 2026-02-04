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
extern int i;
extern uint8_t *src;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    uint32_t local_accum[4] = {0};
    for (i = 0; i < 16; i++) {
        const uint32_t a = ((src[-1 + i * stride]) * 16843009U);
        local_accum[0] ^= a;
        local_accum[1] += a;
        local_accum[2] -= a;
        local_accum[3] ^= (a << 1) | (a >> 31);
        (((av_alias32 *)(((uint32_t *)(src + i * stride)) + 0))->u32 = (a));
        (((av_alias32 *)(((uint32_t *)(src + i * stride)) + 1))->u32 = (a));
        (((av_alias32 *)(((uint32_t *)(src + i * stride)) + 2))->u32 = (a));
        (((av_alias32 *)(((uint32_t *)(src + i * stride)) + 3))->u32 = (a));
    }
    ((av_alias32*)(src + 16 * stride))->u32 = local_accum[0] ^ local_accum[1] ^ local_accum[2] ^ local_accum[3];
}
