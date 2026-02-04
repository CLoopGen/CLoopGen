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

extern uint16_t *src;
extern int stride;
extern int y;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access with unrolled loop and sequential writes
    uint64_t val = ((1 << (12 - 1)) * 281479271743489ULL);
    uint64_t* src64 = (uint64_t*)src;
    for (y = 0; y < 8; y++) {
        ((av_alias64*)(src64 + 0))->u64 = val;
        ((av_alias64*)(src64 + 1))->u64 = val;
        src64 += (stride / sizeof(uint64_t)); // Convert stride to uint64_t units
    }
    src = (uint16_t*)src64; // Update src pointer if needed externally
}
