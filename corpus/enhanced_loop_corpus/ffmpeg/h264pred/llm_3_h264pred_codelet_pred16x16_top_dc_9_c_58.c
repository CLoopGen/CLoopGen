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
    // Variant 2: Strided access with reversed iteration and stride scaling
    ptrdiff_t effective_stride = stride * 2; // Operate on every other row
    uint16_t *ptr = src + (15 * effective_stride); // Start from the end
    for (i = 15; i >= 0; i--) {
        (((av_alias64 *)(ptr + 0))->u64) = dcsplat;
        (((av_alias64 *)(ptr + 4))->u64) = dcsplat;
        (((av_alias64 *)(ptr + 8))->u64) = dcsplat;
        (((av_alias64 *)(ptr + 12))->u64) = dcsplat;
        ptr -= effective_stride; // Traverse backwards with larger stride
    }
}
