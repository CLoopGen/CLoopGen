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
    // Variant 2: Strided access with alternating offset pattern
    ptrdiff_t effective_stride = stride * 2; // Larger stride for irregular access
    for (i = 2; i < 6; i++) {
        uint8_t *row = src + i * effective_stride;
        ((av_alias32 *)(((uint32_t *)row) + 0))->u32 = dc2splat;
        ((av_alias32 *)(((uint32_t *)row) + 2))->u32 = dc2splat; // Skip one, write to next
    }
}
