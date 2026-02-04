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
extern uint16_t *dst;
extern uint64_t val;
extern int y;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided access with alternating offset pattern
    for (y = 0; y < 8; y++) {
        int offset = (y & 1) ? 2 : 6; // Alternating stride-like offsets
        (((av_alias64 *)(dst + offset))->u64 = (val));
        (((av_alias64 *)(dst + offset + 4))->u64 = (val));
        dst += stride;
    }
}
