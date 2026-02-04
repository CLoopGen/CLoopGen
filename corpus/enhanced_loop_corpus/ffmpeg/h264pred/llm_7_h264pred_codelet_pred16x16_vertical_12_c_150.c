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
    for (i = 0; i < 16; i++) {
        uint64_t local_a = a + i; // Eliminate potential loop-carried dependency by making data independent per iteration
        uint64_t local_b = b + i;
        uint64_t local_c = c + i;
        uint64_t local_d = d + i;
        (((av_alias64 *)(((uint64_t *)(src + i * stride)) + 0))->u64 = (local_a));
        (((av_alias64 *)(((uint64_t *)(src + i * stride)) + 1))->u64 = (local_b));
        (((av_alias64 *)(((uint64_t *)(src + i * stride)) + 2))->u64 = (local_c));
        (((av_alias64 *)(((uint64_t *)(src + i * stride)) + 3))->u64 = (local_d));
    }
}
