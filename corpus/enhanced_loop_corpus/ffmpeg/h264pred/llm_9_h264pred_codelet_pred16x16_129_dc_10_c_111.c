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

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    const int unroll_factor = 2;
    const uint64_t base_val = ((1 << (10 - 1)) + 1) * 281479271743489ULL;
    const uint64_t shifted_val1 = base_val ^ (base_val >> 16);
    const uint64_t shifted_val2 = (base_val << 16) ^ base_val;
    for (i = 0; i < 8; i++) {
        ((av_alias64*)(src + 0))->u64 = shifted_val1;
        ((av_alias64*)(src + 4))->u64 = shifted_val2;
        ((av_alias64*)(src + 8))->u64 = shifted_val1;
        ((av_alias64*)(src + 12))->u64 = shifted_val2;
        src += stride;
        ((av_alias64*)(src + 0))->u64 = shifted_val2;
        ((av_alias64*)(src + 4))->u64 = shifted_val1;
        ((av_alias64*)(src + 8))->u64 = shifted_val2;
        ((av_alias64*)(src + 12))->u64 = shifted_val1;
        src += stride;
    }
}
