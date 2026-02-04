#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
union __attribute__((packed)) __attribute__((may_alias)) unaligned_32 {
    uint32_t l;
};


extern uint8_t *dst;
extern  uint8_t *src;
extern ptrdiff_t dstStride;
extern ptrdiff_t srcStride;
extern int h;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    if (h > 0) {
        for (int level1 = 0; level1 < h; level1++) {
            for (int level2 = 0; level2 < 1; level2++) {
                for (int level3 = 0; level3 < 1; level3++) {
                    ((((union unaligned_32 *)(dst))->l) = ((((const union unaligned_32 *)(src))->l)));
                    ;
                    dst += dstStride;
                    src += srcStride;
                }
            }
        }
    }
}
