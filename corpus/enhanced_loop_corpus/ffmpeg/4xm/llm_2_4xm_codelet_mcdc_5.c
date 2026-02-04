#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
union __attribute__((packed)) __attribute__((may_alias)) unaligned_32 {
    uint32_t l;
};


typedef union __attribute__((may_alias)) {
    uint32_t u32;
    uint16_t u16[2];
    uint8_t u8[4];
    float f32;
} av_alias32;

extern uint16_t *dst;
extern  uint16_t *src;
extern int h;
extern int stride;
extern int scale;
extern unsigned int dc;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    // Variant 1: Consecutive memory access with unrolled and coalesced loads/stores
    // Instead of accessing src[0] and src[2] separately (non-consecutive), we process two elements in a tight sequence
    // and change access pattern to be more cache-friendly by ensuring consecutive reads and writes.
    
    for (i = 0; i < h; i++) {
        const uint32_t *src32 = (const uint32_t *)src;
        uint32_t *dst32 = (uint32_t *)dst;

        unsigned int tmpval0 = src32[0] * scale + dc;
        unsigned int tmpval1 = src32[1] * scale + dc;

        ((av_alias32 *)(dst32 + 0))->u32 = tmpval0;
        ((av_alias32 *)(dst32 + 1))->u32 = tmpval1;

        if (scale)
            src += stride;
        dst += stride;
    }
}
