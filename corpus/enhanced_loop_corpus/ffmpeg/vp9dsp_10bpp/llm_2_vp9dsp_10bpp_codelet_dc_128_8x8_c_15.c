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
    // Variant 1: Consecutive memory access with unrolled writes to adjacent locations
    uint64_t *dst64 = (uint64_t *)dst;
    for (y = 0; y < 8; y++) {
        dst64[0] = val;
        dst64[1] = val;
        dst64[2] = val;
        dst64[3] = val;
        dst64 += (stride / sizeof(uint64_t)) * 2; // Advance by two 64-bit values per stride step
    }
}
