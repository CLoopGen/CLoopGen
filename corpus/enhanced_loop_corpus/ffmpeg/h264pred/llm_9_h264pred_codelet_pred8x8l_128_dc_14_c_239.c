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

extern uint16_t *src;
extern int stride;
extern int y;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    const int factor = (1 << (14 - 1));
    uint64_t val1 = factor * 281479271743489ULL;
    uint64_t val2 = val1 + (val1 >> 8);
    uint64_t val3 = val1 - (val1 >> 16);
    uint64_t val4 = val1 ^ (val1 << 7);

    for (y = 0; y < 4; y++) {
        ((av_alias64 *)(((uint64_t *)src) + 0))->u64 = val1;
        ((av_alias64 *)(((uint64_t *)src) + 1))->u64 = val2;
        src += stride;
        ((av_alias64 *)(((uint64_t *)src) + 0))->u64 = val3;
        ((av_alias64 *)(((uint64_t *)src) + 1))->u64 = val4;
        src += stride;
    }
}
