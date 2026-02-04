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
for (i = 0; i < 32; i += 2) {
    const uint64_t a1 = ((src[-1 + i * stride]) * 281479271743489ULL);
    const uint64_t a2 = ((src[-1 + (i + 1) * stride]) * 281479271743489ULL);
    (((av_alias64 *)(((uint64_t *)(src + i * stride)) + 0))->u64 = (a1));
    (((av_alias64 *)(((uint64_t *)(src + i * stride)) + 1))->u64 = (a1));
    (((av_alias64 *)(((uint64_t *)(src + (i + 1) * stride)) + 0))->u64 = (a2));
    (((av_alias64 *)(((uint64_t *)(src + (i + 1) * stride)) + 1))->u64 = (a2));
}
}
