#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef union __attribute__((may_alias)) {
    uint64_t u64;
    uint32_t u32[2];
    uint16_t u16[4];
    uint8_t u8[8];
    double f64;
    float f32[2];
} av_alias64;

extern ptrdiff_t stride;
extern int i;
extern  uint64_t a;
extern uint16_t *src;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < 4; i++) {
        av_alias64 *base0 = (av_alias64 *)((uint64_t *)(src + i * stride));
        av_alias64 *base1 = (av_alias64 *)((uint64_t *)(src + (i + 8) * stride));
        base0->u64 = a ^ 0xAAAAAAAA55555555ULL;
        base0[1].u64 = a ^ 0x55555555AAAAAAAAULL;
        base1->u64 = a ^ 0xFFFFFFFF00000000ULL;
        base1[1].u64 = a ^ 0x00000000FFFFFFFFULL;
    }
}
