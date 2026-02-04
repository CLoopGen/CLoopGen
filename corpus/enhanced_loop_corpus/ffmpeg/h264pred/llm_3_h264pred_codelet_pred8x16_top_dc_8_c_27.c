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
extern uint32_t dc0splat;
extern uint32_t dc1splat;
extern uint8_t *src;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided access with reversed loop order (backward traversal with step of 1)
    for (i = 15; i >= 0; i--) {
        uint32_t *ptr = (uint32_t *)(src + i * stride);
        ((av_alias32 *)(ptr + 0))->u32 = dc0splat;
        ((av_alias32 *)(ptr + 1))->u32 = dc1splat;
    }
}
