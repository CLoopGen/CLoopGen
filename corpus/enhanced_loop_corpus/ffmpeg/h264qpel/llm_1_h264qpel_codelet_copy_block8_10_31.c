#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
union __attribute__((packed)) __attribute__((may_alias)) unaligned_64 {
    uint64_t l;
};


extern uint8_t *dst;
extern  uint8_t *src;
extern int dstStride;
extern int srcStride;
extern int h;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    if (h > 0) {
        int i = 0;
        for (; i < h - 1; i += 2) {
            uint8_t* dst1 = dst + i * dstStride;
            uint8_t* src1 = src + i * srcStride;
            uint8_t* dst2 = dst1 + dstStride;
            uint8_t* src2 = src1 + srcStride;

            ((((union unaligned_64 *)(dst1))->l) = ((((const union unaligned_64 *)(src1))->l)));
            ((((union unaligned_64 *)(dst1 + 4 * sizeof(uint16_t)))->l) = ((((const union unaligned_64 *)(src1 + 4 * sizeof(uint16_t)))->l)));

            ((((union unaligned_64 *)(dst2))->l) = ((((const union unaligned_64 *)(src2))->l)));
            ((((union unaligned_64 *)(dst2 + 4 * sizeof(uint16_t)))->l) = ((((const union unaligned_64 *)(src2 + 4 * sizeof(uint16_t)))->l)));
        }
        if (i < h) {
            uint8_t* dst_offset = dst + i * dstStride;
            uint8_t* src_offset = src + i * srcStride;
            ((((union unaligned_64 *)(dst_offset))->l) = ((((const union unaligned_64 *)(src_offset))->l)));
            ((((union unaligned_64 *)(dst_offset + 4 * sizeof(uint16_t)))->l) = ((((const union unaligned_64 *)(src_offset + 4 * sizeof(uint16_t)))->l)));
        }
    }
}
