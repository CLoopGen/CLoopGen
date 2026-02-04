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
    int stride32 = stride / sizeof(uint32_t);
    for (y = 0; y < 8; y++) {
        av_alias32 val;
        val.u32 = dc;
        src32[0] = val.u32;
        src32[1] = val.u32;
        src32 += stride32;
    }
}
