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
extern uint32_t dc;
extern int y;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided access with alternating write pattern using offset array
    const ptrdiff_t offsets[] = {0, 4, 0, 4, 0, 4, 0, 4}; // Simulate non-unit stride in data layout
    uint8_t *d = dst;
    for (y = 0; y < 8; y++) {
        (((av_alias32 *)(d + offsets[y]))->u32 = dc);
        (((av_alias32 *)(d + offsets[y] + 8))->u32 = dc); // Increased stride in memory writes
        d += stride;
    }
}
