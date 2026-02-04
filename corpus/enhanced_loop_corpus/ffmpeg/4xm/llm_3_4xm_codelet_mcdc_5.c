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



void loop() {
    // Variant 2: Strided memory access with step size increased
    // Modify access pattern to use a larger stride in the source indexing,
    // simulating processing of decimated or sparsely sampled data.
    // We now access every 4th 16-bit element (i.e., strided by 4), treating blocks as sparse samples.

    int effective_stride = stride;  // Base row stride
    int access_stride = 4;          // Access every 4th element in the row

    for (i = 0; i < h; i++) {
        // Strided access: read from src[0] and src[4] instead of src[0] and src[2]
        unsigned int tmpval0 = (((const union unaligned_32 *)(src + 0))->l) * scale + dc;
        unsigned int tmpval1 = (((const union unaligned_32 *)(src + access_stride))->l) * scale + dc;

        (((av_alias32 *)(dst + 0))->u32 = tmpval0);
        (((av_alias32 *)(dst + access_stride))->u32 = tmpval1);

        if (scale)
            src += effective_stride;
        dst += effective_stride;
    }
}
