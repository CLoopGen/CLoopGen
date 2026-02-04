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

extern int y;
extern uint16_t *src;
extern int stride;
extern uint64_t a;
extern uint64_t b;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (y = 2; y < 6; y++) {
    uint64_t temp_a = a + (a >> (y & 7));
    uint64_t temp_b = b ^ (b << ((y + 3) & 7));
    (((av_alias64 *)(((uint64_t *)(src + y * stride)) + 0))->u64 = (temp_a));
    (((av_alias64 *)(((uint64_t *)(src + y * stride)) + 1))->u64 = (temp_b));
    // Unroll one additional assignment per iteration
    (((av_alias64 *)(((uint64_t *)(src + y * stride)) + 2))->u64 = (temp_a ^ temp_b));
    (((av_alias64 *)(((uint64_t *)(src + y * stride)) + 3))->u64 = (temp_b + temp_a));
}
}
