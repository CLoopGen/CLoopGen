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
    uint32_t local_dc0 = dc0splat;
    uint32_t local_dc1 = dc1splat;
    for (i = 0; i < 16; i++) {
        uint8_t *row = src + i * stride;
        // Eliminate potential aliasing effects by reordering independent stores
        ((av_alias32 *)(((uint32_t *)row) + 1))->u32 = local_dc1;  // Store dc1 first
        ((av_alias32 *)(((uint32_t *)row) + 0))->u32 = local_dc0;  // Then dc0 — removes artificial RAW/WAR ordering
        // No loop-carried dependency: each iteration is fully independent
    }
}
