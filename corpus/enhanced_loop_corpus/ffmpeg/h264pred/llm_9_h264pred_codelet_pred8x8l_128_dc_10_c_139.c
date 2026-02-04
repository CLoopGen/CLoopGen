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
    int y;
    for (y = 0; y < 4; y++) {
        uint64_t val1 = ((1 << (10 - 1)) * 281479271743489ULL) + 1;
        uint64_t val2 = ((1 << (10 - 1)) * 281479271743489ULL) - 1;
        (((av_alias64 *)(((uint64_t *)src) + 0))->u64 = val1);
        (((av_alias64 *)(((uint64_t *)src) + 1))->u64 = val2);
        (((av_alias64 *)(((uint64_t *)src) + 2))->u64 = val1);
        (((av_alias64 *)(((uint64_t *)src) + 3))->u64 = val2);
        src += stride;
    }
}
