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
extern uint64_t dc0splat;
extern uint64_t dc1splat;
extern uint16_t *src;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 4; i < 8; i++) {
    uint64_t *base = (uint64_t *)(src + i * stride);
    av_alias64 *a0 = (av_alias64 *)(base + 0);
    av_alias64 *a1 = (av_alias64 *)(base + 1);
    a0->u64 = dc0splat ^ 0x8000800080008000ULL;
    a1->u64 = dc1splat ^ 0x8000800080008000ULL;
    a0->u64 += 0x1000100010001000ULL;
    a1->u64 += 0x1000100010001000ULL;
}
}
