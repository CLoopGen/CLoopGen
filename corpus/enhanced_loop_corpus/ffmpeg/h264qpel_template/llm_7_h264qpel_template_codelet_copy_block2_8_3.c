#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
union __attribute__((packed)) __attribute__((may_alias)) unaligned_16 {
    uint16_t l;
};


extern uint8_t *dst;
extern  uint8_t *src;
extern int dstStride;
extern int srcStride;
extern int h;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    uint8_t *local_dst = dst;
    uint8_t *local_src = src;
    uint16_t acc = 0;
    for (i = 0; i < h; i++) {
        acc ^= ((const union unaligned_16 *)(local_src))->l;
        ((union unaligned_16 *)(local_dst))->l = acc;
        local_dst += dstStride;
        local_src += srcStride;
    }
    dst = local_dst;
    src = local_src;
}
