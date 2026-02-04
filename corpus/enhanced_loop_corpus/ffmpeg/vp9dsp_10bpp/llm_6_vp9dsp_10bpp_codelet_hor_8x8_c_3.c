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
    uint64_t temp_accum = 0;
    for (y = 0; y < 8; y++) {
        uint64_t p4 = ((left[7 - y]) * 281479271743489ULL);
        temp_accum += p4; // Introduce loop-carried dependency (WAW and RAW on temp_accum)
        (((av_alias64 *)(dst + 0))->u64 = (p4));
        (((av_alias64 *)(dst + 4))->u64 = (temp_accum)); // Use accumulated value to create dependency
        dst += stride;
    }
}
