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
extern uint64_t val;
extern int y;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (y = 0; y < 16; y++) {
    uint16_t *base = dst;
    for (int i = 0; i < 8; i++) {
        (((av_alias64 *)(base + i*4))->u64 = (val ^ (uint64_t)(i * y)));
    }
    for (int i = 0; i < 8; i++) {
        (((av_alias64 *)(base + i*4 + 32))->u64 = (val ^ (uint64_t)(i * y + 1)));
    }
    dst += stride;
}
}
