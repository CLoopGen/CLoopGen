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
uint32_t prev_load = 0;
for (i = 0; i < h; i++) {
    uint32_t current_load = (((const union unaligned_32 *)(src))->l);
    uint32_t dependent_val = current_load ^ prev_load;
    ((((union unaligned_32 *)(dst))->l) = dependent_val);
    ((((union unaligned_32 *)(dst + 4 * sizeof(uint8_t)))->l) = ((((const union unaligned_32 *)(src + 4 * sizeof(uint8_t)))->l)));
    ((((union unaligned_32 *)(dst + 8 * sizeof(uint8_t)))->l) = ((((const union unaligned_32 *)(src + 8 * sizeof(uint8_t)))->l)));
    ((((union unaligned_32 *)(dst + 12 * sizeof(uint8_t)))->l) = ((((const union unaligned_32 *)(src + 12 * sizeof(uint8_t)))->l)));
    prev_load = current_load;
    dst += dstStride;
    src += srcStride;
}
}
