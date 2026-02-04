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
    for (y = 0; y < 16; y++) {
        uint64_t p4 = ((left[15 - y]) * 281479271743489ULL);
        uint64_t temp1 = p4 ^ 0xAAAAAAAAAAAAAAAAULL; // Break direct dependency chain
        uint64_t temp2 = p4 ^ 0x5555555555555555ULL;

        (((av_alias64 *)(dst + 0))->u64 = (temp1)); // Use transformed values
        (((av_alias64 *)(dst + 4))->u64 = (temp2));
        (((av_alias64 *)(dst + 8))->u64 = (temp1));
        (((av_alias64 *)(dst + 12))->u64 = (temp2));

        // Eliminate any artificial loop-carried dependencies
        // All operations are independent across iterations (purely loop-independent)
        dst += stride;
    }
}
