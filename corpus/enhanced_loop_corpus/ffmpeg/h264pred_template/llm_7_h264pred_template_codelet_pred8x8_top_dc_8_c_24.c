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
    uint32_t local_dc0splat = dc0splat;
    uint32_t local_dc1splat = dc1splat;
    uint8_t *local_src = src;
    ptrdiff_t local_stride = stride;
    for (i = 0; i < 4; i++) {
        uint8_t *row = local_src + i * local_stride;
        // Remove potential aliasing effects by reordering independent stores
        ((av_alias32 *)(((uint32_t *)row) + 1))->u32 = local_dc1splat;
        ((av_alias32 *)(((uint32_t *)row) + 0))->u32 = local_dc0splat;
        // Eliminate loop-carried dependency; each iteration is now fully independent
    }
}
