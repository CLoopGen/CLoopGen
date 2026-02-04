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
    // Variant 2: Strided access with reversed iteration and stride scaling
    ptrdiff_t scaled_stride = stride * 2; // Effectively skip one row each time
    uint16_t *temp_src = src + (15 * scaled_stride / sizeof(uint16_t)); // Start from an effective offset
    for (i = 15; i >= 0; i--) {
        ((av_alias64 *)(temp_src + 0))->u64 = ((1 << (14 - 1)) + 0) * 281479271743489ULL;
        ((av_alias64 *)(temp_src + 4))->u64 = ((1 << (14 - 1)) + 0) * 281479271743489ULL;
        ((av_alias64 *)(temp_src + 8))->u64 = ((1 << (14 - 1)) + 0) * 281479271743489ULL;
        ((av_alias64 *)(temp_src + 12))->u64 = ((1 << (14 - 1)) + 0) * 281479271743489ULL;
        temp_src -= scaled_stride / sizeof(uint16_t);
    }
}
