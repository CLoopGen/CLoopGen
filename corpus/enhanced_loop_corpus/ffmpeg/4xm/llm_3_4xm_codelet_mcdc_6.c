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



void loop(){
// Strided memory access with increasing stride over iterations
int effective_stride = 2;
for (i = 0; i < h; i++) {
    // Access elements using a dynamic strided pattern: 0, 2*stride_mod, 4*stride_mod, 6*stride_mod
    int idx0 = 0;
    int idx1 = effective_stride;
    int idx2 = 2 * effective_stride;
    int idx3 = 3 * effective_stride;

    unsigned int tmpval0 = ((const union unaligned_32 *)(src + idx0))->l * scale + dc;
    unsigned int tmpval1 = ((const union unaligned_32 *)(src + idx1))->l * scale + dc;
    unsigned int tmpval2 = ((const union unaligned_32 *)(src + idx2))->l * scale + dc;
    unsigned int tmpval3 = ((const union unaligned_32 *)(src + idx3))->l * scale + dc;

    ((av_alias32 *)(dst + idx0))->u32 = tmpval0;
    ((av_alias32 *)(dst + idx1))->u32 = tmpval1;
    ((av_alias32 *)(dst + idx2))->u32 = tmpval2;
    ((av_alias32 *)(dst + idx3))->u32 = tmpval3;

    // Increase stride each row to create a widening access pattern
    effective_stride += 1;

    if (scale)
        src += stride;
    dst += stride;
}
}
