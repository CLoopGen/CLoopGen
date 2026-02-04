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
    for (i = 0; i < 32; i += 2) {
        uint64_t val = ((1ULL << 13) - 1) * 281479271743489ULL;
        ((av_alias64*)(src + 0))->u64 = val;
        ((av_alias64*)(src + 4))->u64 = val;
        ((av_alias64*)(src + 8))->u64 = val;
        ((av_alias64*)(src + 12))->u64 = val;
        src += stride;

        // Unrolled second iteration
        ((av_alias64*)(src + 0))->u64 = val;
        ((av_alias64*)(src + 4))->u64 = val;
        ((av_alias64*)(src + 8))->u64 = val;
        ((av_alias64*)(src + 12))->u64 = val;
        src += stride;
    }
}
