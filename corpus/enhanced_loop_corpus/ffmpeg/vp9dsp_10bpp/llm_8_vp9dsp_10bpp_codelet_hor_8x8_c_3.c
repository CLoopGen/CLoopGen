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
extern  uint16_t *left;
extern int y;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (y = 0; y < 16; y += 2) {
    uint64_t p4 = ((left[7 - (y % 8)]) * 281479271743489ULL);
    uint64_t p5 = ((left[(7 - (y % 8)) ^ 1]) * 140737488355329ULL);
    (((av_alias64 *)(dst + 0))->u64 = (p4 ^ p5));
    (((av_alias64 *)(dst + 4))->u64 = (p4));
    dst += stride;
}
}
