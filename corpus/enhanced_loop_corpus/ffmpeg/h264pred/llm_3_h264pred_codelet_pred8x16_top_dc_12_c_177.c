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
    // Variant 2: Strided access with fixed offset step (simulate wider stride or channel-like structure)
    ptrdiff_t effective_stride = stride * 2; // Double the original stride for a more spread-out access pattern
    for (i = 0; i < 16; i++) {
        uint16_t *p = src + i * effective_stride;
        (((av_alias64 *)(((uint64_t *)(p)) + 0))->u64 = (dc0splat));
        (((av_alias64 *)(((uint64_t *)(p)) + 1))->u64 = (dc1splat));
    }
}
