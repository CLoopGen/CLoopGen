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
    // Variant 2: Strided access with transposed write pattern (vertical traversal)
    uint16_t *col0 = src;
    for (i = 0; i < 16; i++) {
        ((av_alias64 *)(col0 + 0))->u64 = dcsplat;
        ((av_alias64 *)(col0 + 4))->u64 = dcsplat;
        ((av_alias64 *)(col0 + 8))->u64 = dcsplat;
        ((av_alias64 *)(col0 + 12))->u64 = dcsplat;
        col0 = (uint16_t *)((uint8_t *)col0 + stride);
    }
}
