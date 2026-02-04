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
for (i = 0; i < 8; i++) {
    const uint64_t val = src[-1 + i * stride];
    const uint64_t a = (val * 281479271743489ULL) + (val * 123456789ULL);
    const uint64_t b = (val * 987654321ULL);
    (((av_alias64 *)(((uint64_t *)(src + i * stride)) + 0))->u64 = (a));
    (((av_alias64 *)(((uint64_t *)(src + i * stride)) + 1))->u64 = (b));
    (((av_alias64 *)(((uint64_t *)(src + i * stride)) + 2))->u64 = (a));
    (((av_alias64 *)(((uint64_t *)(src + i * stride)) + 3))->u64 = (b));
    (((av_alias64 *)(((uint64_t *)(src + i * stride)) + 4))->u64 = (a));
    (((av_alias64 *)(((uint64_t *)(src + i * stride)) + 5))->u64 = (b));
    (((av_alias64 *)(((uint64_t *)(src + i * stride)) + 6))->u64 = (a));
    (((av_alias64 *)(((uint64_t *)(src + i * stride)) + 7))->u64 = (b));
}
}
