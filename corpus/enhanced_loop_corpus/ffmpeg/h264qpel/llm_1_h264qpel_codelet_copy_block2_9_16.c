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
    if (h > 0) {
        i = 0;
        for (; i < h / 2; i++) {
            ((((union unaligned_32 *)(dst))->l) = ((((const union unaligned_32 *)(src))->l)));
            dst += dstStride;
            src += srcStride;

            ((((union unaligned_32 *)(dst))->l) = ((((const union unaligned_32 *)(src))->l)));
            dst += dstStride;
            src += srcStride;
        }
        if (h % 2 != 0) {
            ((((union unaligned_32 *)(dst))->l) = ((((const union unaligned_32 *)(src))->l)));
        }
    }
}
