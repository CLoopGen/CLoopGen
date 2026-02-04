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
for (i = 0; i < 16; i++) {
    uint16_t *base = src + i * (stride / sizeof(uint16_t));
    (((av_alias64 *)(base + 0))->u64 = ((((1 << (10 - 1)) + 1) * 281479271743489ULL)));
    (((av_alias64 *)(base + 4))->u64 = ((((1 << (10 - 1)) + 1) * 281479271743489ULL)));
    (((av_alias64 *)(base + 8))->u64 = ((((1 << (10 - 1)) + 1) * 281479271743489ULL)));
    (((av_alias64 *)(base + 12))->u64 = ((((1 << (10 - 1)) + 1) * 281479271743489ULL)));
}
}
