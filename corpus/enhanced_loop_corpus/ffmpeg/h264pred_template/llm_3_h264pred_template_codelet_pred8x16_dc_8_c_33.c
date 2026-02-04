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
extern uint32_t dc3splat;
extern uint8_t *src;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided memory access with vertical traversal — process all rows' first element, then second
    uint8_t *start = src + 4 * stride;
    // First handle the first 32-bit word across all iterations
    for (i = 0; i < 4; i++) {
        ((av_alias32 *)(((uint32_t *)(start + i * stride)) + 0))->u32 = dc2splat;
    }
    // Then handle the second 32-bit word across all iterations
    for (i = 0; i < 4; i++) {
        ((av_alias32 *)(((uint32_t *)(start + i * stride)) + 1))->u32 = dc3splat;
    }
}
