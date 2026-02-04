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
    uint16_t *access_pattern[4] = {
        src + 0, src + 8, src + 16, src + 24
    };
    (((av_alias64 *)(access_pattern[0]))->u64 = ((((1 << (9 - 1)) + 1) * 281479271743489ULL)));
    (((av_alias64 *)(access_pattern[1]))->u64 = ((((1 << (9 - 1)) + 1) * 281479271743489ULL)));
    (((av_alias64 *)(access_pattern[2]))->u64 = ((((1 << (9 - 1)) + 1) * 281479271743489ULL)));
    (((av_alias64 *)(access_pattern[3]))->u64 = ((((1 << (9 - 1)) + 1) * 281479271743489ULL)));
    src += stride;
}
}
