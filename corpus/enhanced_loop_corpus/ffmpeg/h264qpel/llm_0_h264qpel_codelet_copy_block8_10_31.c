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
    for (int outer = 0; outer < h / 2; outer++) {
        for (int inner = 0; inner < 2; inner++) {
            int idx = outer * 2 + inner;
            uint8_t* dst_offset = dst + idx * dstStride;
            uint8_t* src_offset = src + idx * srcStride;
            ((((union unaligned_64 *)(dst_offset))->l) = ((((const union unaligned_64 *)(src_offset))->l)));
            ((((union unaligned_64 *)(dst_offset + 4 * sizeof(uint16_t)))->l) = ((((const union unaligned_64 *)(src_offset + 4 * sizeof(uint16_t)))->l)));
        }
    }
    if (h % 2 != 0) {
        int idx = h - 1;
        uint8_t* dst_offset = dst + idx * dstStride;
        uint8_t* src_offset = src + idx * srcStride;
        ((((union unaligned_64 *)(dst_offset))->l) = ((((const union unaligned_64 *)(src_offset))->l)));
        ((((union unaligned_64 *)(dst_offset + 4 * sizeof(uint16_t)))->l) = ((((const union unaligned_64 *)(src_offset + 4 * sizeof(uint16_t)))->l)));
    }
}
