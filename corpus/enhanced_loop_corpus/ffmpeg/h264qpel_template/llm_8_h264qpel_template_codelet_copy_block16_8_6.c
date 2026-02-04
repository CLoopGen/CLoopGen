#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
union __attribute__((packed)) __attribute__((may_alias)) unaligned_32 {
    uint32_t l;
};


extern uint8_t *dst;
extern  uint8_t *src;
extern int dstStride;
extern int srcStride;
extern int h;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < h; i += 2) {
    if (i + 1 < h) {
        ((((union unaligned_32 *)(dst))->l) = ((((const union unaligned_32 *)(src))->l)));
        ((((union unaligned_32 *)(dst + 4 * sizeof(uint8_t)))->l) = ((((const union unaligned_32 *)(src + 4 * sizeof(uint8_t)))->l)));
        ((((union unaligned_32 *)(dst + 8 * sizeof(uint8_t)))->l) = ((((const union unaligned_32 *)(src + 8 * sizeof(uint8_t)))->l)));
        ((((union unaligned_32 *)(dst + 12 * sizeof(uint8_t)))->l) = ((((const union unaligned_32 *)(src + 12 * sizeof(uint8_t)))->l)));

        uint8_t *dst_next = dst + dstStride;
        uint8_t *src_next = src + srcStride;

        ((((union unaligned_32 *)(dst_next))->l) = ((((const union unaligned_32 *)(src_next))->l)));
        ((((union unaligned_32 *)(dst_next + 4 * sizeof(uint8_t)))->l) = ((((const union unaligned_32 *)(src_next + 4 * sizeof(uint8_t)))->l)));
        ((((union unaligned_32 *)(dst_next + 8 * sizeof(uint8_t)))->l) = ((((const union unaligned_32 *)(src_next + 8 * sizeof(uint8_t)))->l)));
        ((((union unaligned_32 *)(dst_next + 12 * sizeof(uint8_t)))->l) = ((((const union unaligned_32 *)(src_next + 12 * sizeof(uint8_t)))->l)));

        dst += 2 * dstStride;
        src += 2 * srcStride;
    } else {
        ((((union unaligned_32 *)(dst))->l) = ((((const union unaligned_32 *)(src))->l)));
        ((((union unaligned_32 *)(dst + 4 * sizeof(uint8_t)))->l) = ((((const union unaligned_32 *)(src + 4 * sizeof(uint8_t)))->l)));
        ((((union unaligned_32 *)(dst + 8 * sizeof(uint8_t)))->l) = ((((const union unaligned_32 *)(src + 8 * sizeof(uint8_t)))->l)));
        ((((union unaligned_32 *)(dst + 12 * sizeof(uint8_t)))->l) = ((((const union unaligned_32 *)(src + 12 * sizeof(uint8_t)))->l)));
        dst += dstStride;
        src += srcStride;
    }
}
}
