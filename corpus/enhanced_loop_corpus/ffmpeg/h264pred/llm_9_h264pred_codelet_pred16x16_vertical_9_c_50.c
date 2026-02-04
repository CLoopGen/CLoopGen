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
extern  uint64_t c;
extern  uint64_t d;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < 8; i += 2) {
    uint64_t temp_a = a + 1;
    uint64_t temp_b = b - 1;
    uint64_t temp_c = c + 2;
    uint64_t temp_d = d - 2;

    (((av_alias64 *)(((uint64_t *)(src + i * stride)) + 0))->u64 = (temp_a));
    (((av_alias64 *)(((uint64_t *)(src + i * stride)) + 1))->u64 = (temp_b));
    (((av_alias64 *)(((uint64_t *)(src + i * stride)) + 2))->u64 = (temp_c));
    (((av_alias64 *)(((uint64_t *)(src + i * stride)) + 3))->u64 = (temp_d));

    // Second iteration unrolled manually within the same loop step
    (((av_alias64 *)(((uint64_t *)(src + (i+1) * stride)) + 0))->u64 = (temp_a ^ 0xFFFF));
    (((av_alias64 *)(((uint64_t *)(src + (i+1) * stride)) + 1))->u64 = (temp_b ^ 0xFFFF));
    (((av_alias64 *)(((uint64_t *)(src + (i+1) * stride)) + 2))->u64 = (temp_c ^ 0xFFFF));
    (((av_alias64 *)(((uint64_t *)(src + (i+1) * stride)) + 3))->u64 = (temp_d ^ 0xFFFF));
}
}
