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
    for (i = 0; i < 4; i++) {
        int base_idx = i * 4;
        (((av_alias64 *)(((uint64_t *)(src + (base_idx + 0) * stride)) + 0))->u64 = (a));
        (((av_alias64 *)(((uint64_t *)(src + (base_idx + 0) * stride)) + 1))->u64 = (b));
        (((av_alias64 *)(((uint64_t *)(src + (base_idx + 0) * stride)) + 2))->u64 = (c));
        (((av_alias64 *)(((uint64_t *)(src + (base_idx + 0) * stride)) + 3))->u64 = (d));

        (((av_alias64 *)(((uint64_t *)(src + (base_idx + 1) * stride)) + 0))->u64 = (a));
        (((av_alias64 *)(((uint64_t *)(src + (base_idx + 1) * stride)) + 1))->u64 = (b));
        (((av_alias64 *)(((uint64_t *)(src + (base_idx + 1) * stride)) + 2))->u64 = (c));
        (((av_alias64 *)(((uint64_t *)(src + (base_idx + 1) * stride)) + 3))->u64 = (d));

        (((av_alias64 *)(((uint64_t *)(src + (base_idx + 2) * stride)) + 0))->u64 = (a));
        (((av_alias64 *)(((uint64_t *)(src + (base_idx + 2) * stride)) + 1))->u64 = (b));
        (((av_alias64 *)(((uint64_t *)(src + (base_idx + 2) * stride)) + 2))->u64 = (c));
        (((av_alias64 *)(((uint64_t *)(src + (base_idx + 2) * stride)) + 3))->u64 = (d));

        (((av_alias64 *)(((uint64_t *)(src + (base_idx + 3) * stride)) + 0))->u64 = (a));
        (((av_alias64 *)(((uint64_t *)(src + (base_idx + 3) * stride)) + 1))->u64 = (b));
        (((av_alias64 *)(((uint64_t *)(src + (base_idx + 3) * stride)) + 2))->u64 = (c));
        (((av_alias64 *)(((uint64_t *)(src + (base_idx + 3) * stride)) + 3))->u64 = (d));
    }
}
