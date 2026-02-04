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
    // Variant 2: Strided access with fixed offset step using pointer arithmetic unrolling
    // Simulate wider stride interpretation or channel interleaving
    uint32_t *row_start = (uint32_t*)(src + 4 * stride);
    ptrdiff_t effective_stride = stride / sizeof(uint32_t); // convert to uint32_t units
    for (i = 0; i < 4; i++) {
        av_alias32 *pos0 = (av_alias32*)(row_start + i * effective_stride);
        av_alias32 *pos1 = (av_alias32*)(row_start + i * effective_stride + 1);
        pos0->u32 = dc0splat;
        pos1->u32 = dc1splat;
    }
}
