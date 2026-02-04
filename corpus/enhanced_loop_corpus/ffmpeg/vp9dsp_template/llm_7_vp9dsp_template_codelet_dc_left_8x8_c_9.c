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
extern uint32_t dc;
extern int y;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    uint8_t *local_dst = dst;
    uint32_t local_dc = dc;
    ptrdiff_t local_stride = stride;
    for (y = 0; y < 8; y++) {
        ((av_alias32 *)(local_dst + 0))->u32 = local_dc;
        ((av_alias32 *)(local_dst + 4))->u32 = local_dc;
        local_dst += local_stride; // Eliminate loop-carried dependency on global 'dst'
    }
    dst = local_dst; // Update global only after loop
}
