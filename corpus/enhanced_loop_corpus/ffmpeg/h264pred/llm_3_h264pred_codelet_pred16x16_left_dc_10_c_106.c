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
    // Variant 2: Strided access with transposed write pattern using fixed offsets and stride scaling
    uint16_t *base = src;
    for (i = 0; i < 16; i++) {
        // Access every 4th element in a strided pattern across multiple rows
        (((av_alias64 *)(base + 0 * stride))->u64 = dcsplat);
        (((av_alias64 *)(base + 1 * stride))->u64 = dcsplat);
        (((av_alias64 *)(base + 2 * stride))->u64 = dcsplat);
        (((av_alias64 *)(base + 3 * stride))->u64 = dcsplat);
        base += 4; // Advance column index by 4 uint16_t positions
    }
}
