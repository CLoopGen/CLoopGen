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
extern uint16_t *src;
extern uint64_t dcsplat;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    uint64_t local_dc = dcsplat;
    for (i = 0; i < 16; i++) {
        // Remove potential write-after-write hazards by interleaving independent writes
        // Split the stores to break false dependencies and allow better pipelining
        av_alias64 *a0 = (av_alias64*)(src + 0);
        av_alias64 *a4 = (av_alias64*)(src + 4);
        av_alias64 *a8 = (av_alias64*)(src + 8);
        av_alias64 *a12 = (av_alias64*)(src + 12);

        a0->u64 = local_dc;
        a8->u64 = local_dc;
        a4->u64 = local_dc;
        a12->u64 = local_dc;

        src += stride;
    }
}
