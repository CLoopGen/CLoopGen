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
    uint64_t base_val = ((1 << (10 - 1)) + 0) * 281479271743489ULL;
    uint64_t shift_val = (base_val >> 4) | (base_val << 60); // Rotate right by 4
    (((av_alias64 *)(src + 0))->u64 = base_val);
    (((av_alias64 *)(src + 4))->u64 = shift_val);
    (((av_alias64 *)(src + 8))->u64 = (base_val + shift_val) ^ base_val);
    (((av_alias64 *)(src + 12))->u64 = (shift_val * 3) & 0xFFFFFFFFFFFFFFF0ULL);
    src += stride;
    // Unrolled variant with reduced trip count but more operations per iteration
}
}
