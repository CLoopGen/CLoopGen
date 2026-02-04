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
    // Variant 2: Strided memory access — write every other 32-bit element, stepping by 2 in each row
    for (y = 0; y < 16; y++) {
        (((av_alias32 *)(dst + 0))->u32 = (val));
        (((av_alias32 *)(dst + 8))->u32 = (val)); // Skip one 32-bit value
        (((av_alias32 *)(dst + 16))->u32 = (val));
        (((av_alias32 *)(dst + 24))->u32 = (val)); // Increased stride in access pattern
        dst += stride;
    }
}
