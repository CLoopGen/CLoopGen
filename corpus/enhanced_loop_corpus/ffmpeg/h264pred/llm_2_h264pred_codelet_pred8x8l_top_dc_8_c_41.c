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

extern uint8_t *src;
extern int stride;
extern  uint32_t dc;
extern int y;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access with unrolled loop and sequential writes
    uint32_t *src32 = (uint32_t *)src;
    for (y = 0; y < 8; y++) {
        av_alias32 *a = (av_alias32 *)(src32);
        a[0].u32 = dc;
        a[1].u32 = dc;
        src32 = (uint32_t *)((uint8_t *)src32 + stride); // Update pointer using stride in bytes
    }
    src = (uint8_t *)src32 - 8 * stride; // Restore src base if needed (optional, depending on context)
}
