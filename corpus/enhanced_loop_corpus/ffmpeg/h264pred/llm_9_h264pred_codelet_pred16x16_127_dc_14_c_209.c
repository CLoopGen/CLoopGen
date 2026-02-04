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
    const int factor = (1 << (14 - 1)) - 1;
    uint64_t base_val = 281479271743489ULL;
    uint64_t val1 = factor * base_val;
    uint64_t val2 = (factor * (base_val >> 1)) ^ 0x1234567812345678ULL;
    uint64_t val3 = (factor * (base_val >> 2)) & 0xFFFFFFFFFFFF0000ULL;
    uint64_t val4 = (factor * (base_val >> 3)) | 0x000000000000FFFFULL;

    for (i = 0; i < 8; i++) {
        ((av_alias64*)(src + 0))->u64 = val1;
        ((av_alias64*)(src + 4))->u64 = val2;
        ((av_alias64*)(src + 8))->u64 = val3;
        ((av_alias64*)(src + 12))->u64 = val4;
        src += stride;

        // Additional computational work per iteration
        val1 ^= val2;
        val3 += val4;
        val2 = (val2 >> 1) | (val1 << 63);
        val4 = __builtin_bswap64(val3);
    }
}
