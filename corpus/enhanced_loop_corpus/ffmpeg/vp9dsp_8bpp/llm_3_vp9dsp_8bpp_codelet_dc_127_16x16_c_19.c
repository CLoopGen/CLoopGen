#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef union __attribute__((may_alias)) {
    uint32_t u32;
    uint16_t u16[2];
    uint8_t u8[4];
    float f32;
} av_alias32;

extern ptrdiff_t stride;
extern uint8_t *dst;
extern uint32_t val;
extern int y;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided access with reversed row traversal
    uint8_t *base = dst + 15 * stride;  // Start from the last row
    for (y = 0; y < 16; y++) {
        uint8_t *d = base - y * stride;  // Access rows in reverse order
        ((av_alias32 *)(d + 0))->u32 = val;
        ((av_alias32 *)(d + 4))->u32 = val;
        ((av_alias32 *)(d + 8))->u32 = val;
        ((av_alias32 *)(d + 12))->u32 = val;
    }
}
