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
extern uint16_t *dst;
extern uint64_t val;
extern int y;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    uint64_t local_val[4];
    local_val[0] = val;
    local_val[1] = val ^ 0xFFFFFFFF00000000ULL;
    local_val[2] = val ^ 0x00000000FFFFFFFFULL;
    local_val[3] = val;

    for (y = 0; y < 16; y++) {
        ((av_alias64*)(dst + 0))->u64 = local_val[0];
        ((av_alias64*)(dst + 4))->u64 = local_val[1];
        ((av_alias64*)(dst + 8))->u64 = local_val[2];
        ((av_alias64*)(dst + 12))->u64 = local_val[3];

        local_val[0] ^= val;
        local_val[1] ^= val;
        local_val[2] ^= val;
        local_val[3] ^= val;

        dst += stride;
    }
}
