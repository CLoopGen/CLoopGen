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
    uint64_t values[4];
    uint64_t seed = (((1 << (14 - 1)) + 1) * 281479271743489ULL);
    values[0] = seed;
    values[1] = seed ^ 0xAAAAAAAAAAAAAAAAULL;
    values[2] = seed ^ 0x5555555555555555ULL;
    values[3] = seed ^ 0xFFFFFFFFFFFFFFFFULL;

    for (i = 0; i < 16; i++) {
        ((av_alias64*)(src + 0))->u64 = values[(i + 0) & 3];
        ((av_alias64*)(src + 4))->u64 = values[(i + 1) & 3];
        ((av_alias64*)(src + 8))->u64 = values[(i + 2) & 3];
        ((av_alias64*)(src + 12))->u64 = values[(i + 3) & 3];

        src += stride;
    }
}
