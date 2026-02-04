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

extern int i;
extern uint16_t *src;
extern int stride;
extern  uint64_t a;
extern  uint64_t b;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < 32; i += 2) {
    uint64_t *ptr = (uint64_t *)(src + i * stride);
    (((av_alias64 *)(ptr + 0))->u64 = (a ^ 0x8000800080008000ULL));
    (((av_alias64 *)(ptr + 1))->u64 = (b ^ 0x8000800080008000ULL));
    (((av_alias64 *)(ptr + 2))->u64 = (a ^ 0x4000400040004000ULL));
    (((av_alias64 *)(ptr + 3))->u64 = (b ^ 0x4000400040004000ULL));
}
}
