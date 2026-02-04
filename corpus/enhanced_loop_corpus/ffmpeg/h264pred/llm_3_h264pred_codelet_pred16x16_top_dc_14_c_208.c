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
    // Variant 2: Strided access with non-unit stride across iterations
    uint16_t *base = src;
    ptrdiff_t effective_stride = stride * 4; // Larger stride over iterations
    for (i = 0; i < 16; i++) {
        uint16_t *row = base + i * effective_stride;
        ((av_alias64 *)(row + 0))->u64 = dcsplat;
        ((av_alias64 *)(row + 4))->u64 = dcsplat;
        ((av_alias64 *)(row + 8))->u64 = dcsplat;
        ((av_alias64 *)(row + 12))->u64 = dcsplat;
    }
}
