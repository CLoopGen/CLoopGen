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
    av_alias32 *base_ptr = (av_alias32*)(src);
    ptrdiff_t offset_in_u32 = stride / sizeof(uint32_t);
    for (i = 0; i < 16; i++) {
        ptrdiff_t row_offset = i * offset_in_u32;
        ((av_alias32*)((uint32_t*)src + row_offset) + 0)->u32 = local_dc0splat;
        ((av_alias32*)((uint32_t*)src + row_offset) + 1)->u32 = local_dc1splat;
        // Eliminate potential aliasing side effects by using locals, no loop-carried dependencies
        // All iterations are independent — enhances parallelism
    }
}
