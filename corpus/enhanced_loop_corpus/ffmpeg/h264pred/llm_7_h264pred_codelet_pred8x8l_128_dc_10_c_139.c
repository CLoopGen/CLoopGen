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
    const uint64_t base_val = ((1ULL << (10 - 1)) * 281479271743489ULL);
    uint64_t offset_multiplier = 1;
    for (y = 0; y < 8; y++) {
        uint64_t scaled_val0 = base_val * offset_multiplier;
        uint64_t scaled_val1 = base_val * (offset_multiplier + 1);
        (((av_alias64 *)(((uint64_t *)src) + 0))->u64) = scaled_val0;
        (((av_alias64 *)(((uint64_t *)src) + 1))->u64) = scaled_val1;
        offset_multiplier += 2; // Create loop-carried RAW dependency
        src += stride;
    }
}
