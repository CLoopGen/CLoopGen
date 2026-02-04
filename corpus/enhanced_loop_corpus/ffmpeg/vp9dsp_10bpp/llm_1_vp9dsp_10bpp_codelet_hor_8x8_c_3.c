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
extern  uint16_t *left;
extern int y;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (y = 0; y < 4; y++) { // Decreased effective loop depth by reducing iterations and unrolling
        uint64_t p4_0 = ((left[7 - y]) * 281479271743489ULL);
        (((av_alias64 *)(dst + 0))->u64 = (p4_0));
        (((av_alias64 *)(dst + 4))->u64 = (p4_0));
        dst += stride;

        uint64_t p4_1 = ((left[7 - (y + 4)]) * 281479271743489ULL);
        (((av_alias64 *)(dst + 0))->u64 = (p4_1));
        (((av_alias64 *)(dst + 4))->u64 = (p4_1));
        dst += stride;
    }
}
