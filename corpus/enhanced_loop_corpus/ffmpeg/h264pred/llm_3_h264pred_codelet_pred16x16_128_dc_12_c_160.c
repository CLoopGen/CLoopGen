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
extern uint16_t *src;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect memory access using an index array
    // Simulates non-contiguous, scatter-style access through precomputed offsets
    static const int offsets[16] = {0, 2, 4, 6, 1, 3, 5, 7, 8, 10, 12, 14, 9, 11, 13, 15};
    uint16_t *access_pattern[16];
    for (i = 0; i < 16; i++) {
        access_pattern[i] = src + offsets[i] * 8;  // Each points to a different block
    }
    for (i = 0; i < 16; i++) {
        uint16_t *p = access_pattern[i];
        ((av_alias64 *)(p + 0))->u64 = (((1 << (12 - 1)) + 0) * 281479271743489ULL);
        ((av_alias64 *)(p + 4))->u64 = (((1 << (12 - 1)) + 0) * 281479271743489ULL);
        ((av_alias64 *)(p + 8))->u64 = (((1 << (12 - 1)) + 0) * 281479271743489ULL);
        ((av_alias64 *)(p + 12))->u64 = (((1 << (12 - 1)) + 0) * 281479271743489ULL);
    }
}
