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
    uint16_t *access_pattern[8];
    for (y = 0; y < 8; y++) {
        access_pattern[y] = src + y * stride;
    }
    for (y = 0; y < 8; y++) {
        uint16_t *p = access_pattern[y];
        (((av_alias64 *)(((uint64_t *)p) + 0))->u64 = (((1 << (14 - 1)) * 281479271743489ULL)));
        (((av_alias64 *)(((uint64_t *)p) + 1))->u64 = (((1 << (14 - 1)) * 281479271743489ULL)));
    }
}
