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
        do {
            ((((union unaligned_64 *)(dst + 0 * dstStride))->l) = ((((const union unaligned_64 *)(src + 0 * srcStride))->l)));
            ((((union unaligned_64 *)(dst + 0 * dstStride + 4 * sizeof(uint16_t)))->l) = ((((const union unaligned_64 *)(src + 0 * srcStride + 4 * sizeof(uint16_t)))->l)));
            i++;
        } while (i < h);
    }
}
