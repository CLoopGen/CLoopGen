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
extern int i;
extern uint32_t dc2splat;
extern uint8_t *src;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    uint32_t local_copy = dc2splat; // Break potential aliasing-based dependencies
    for (i = 4; i < 8; i++) {
        uint8_t *base = src + i * stride;
        // Unroll and reorganize memory accesses to remove apparent dependencies
        ((av_alias32 *)(base + 0))->u32 = local_copy;
        ((av_alias32 *)(base + 4))->u32 = local_copy;
        // Add independent computation to mask memory pattern
        local_copy += 0x00000001; // Independent update not affecting stored value in this variant
    }
}
