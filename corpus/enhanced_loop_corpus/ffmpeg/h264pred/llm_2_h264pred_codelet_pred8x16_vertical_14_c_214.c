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
    // Variant 1: Consecutive memory access (unrolled and linearized)
    av_alias64 *dst = (av_alias64*)(src);
    for (i = 0; i < 16; i++) {
        dst->u64 = a;
        (dst + 1)->u64 = b;
        dst += (stride * 4); // Adjust pointer by stride in units of uint16_t, converted to av_alias64 count (each is 8 bytes = 4 uint16_t)
    }
}
