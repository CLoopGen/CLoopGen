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
extern uint64_t dcsplat;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided access with transposed write pattern - writing every 16th element
    uint16_t *temp_src = src;
    ptrdiff_t effective_stride = stride / sizeof(uint16_t);
    for (i = 0; i < 4; i++) {
        // Unroll the inner writes across iterations
        ((av_alias64 *)(temp_src + 0 * effective_stride))->u64 = dcsplat;
        ((av_alias64 *)(temp_src + 1 * effective_stride))->u64 = dcsplat;
        ((av_alias64 *)(temp_src + 2 * effective_stride))->u64 = dcsplat;
        ((av_alias64 *)(temp_src + 3 * effective_stride))->u64 = dcsplat;
        ((av_alias64 *)(temp_src + 4 * effective_stride))->u64 = dcsplat;
        ((av_alias64 *)(temp_src + 5 * effective_stride))->u64 = dcsplat;
        ((av_alias64 *)(temp_src + 6 * effective_stride))->u64 = dcsplat;
        ((av_alias64 *)(temp_src + 7 * effective_stride))->u64 = dcsplat;
        ((av_alias64 *)(temp_src + 8 * effective_stride))->u64 = dcsplat;
        ((av_alias64 *)(temp_src + 9 * effective_stride))->u64 = dcsplat;
        ((av_alias64 *)(temp_src + 10 * effective_stride))->u64 = dcsplat;
        ((av_alias64 *)(temp_src + 11 * effective_stride))->u64 = dcsplat;
        ((av_alias64 *)(temp_src + 12 * effective_stride))->u64 = dcsplat;
        ((av_alias64 *)(temp_src + 13 * effective_stride))->u64 = dcsplat;
        ((av_alias64 *)(temp_src + 14 * effective_stride))->u64 = dcsplat;
        ((av_alias64 *)(temp_src + 15 * effective_stride))->u64 = dcsplat;
        temp_src += 4; // Advance source pointer by 4 elements (simulating column-wise store)
    }
}
