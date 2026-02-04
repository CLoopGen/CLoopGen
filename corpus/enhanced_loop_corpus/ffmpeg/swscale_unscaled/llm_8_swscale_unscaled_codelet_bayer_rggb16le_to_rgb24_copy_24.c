#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
union __attribute__((packed)) __attribute__((may_alias)) unaligned_16 {
    uint16_t l;
};


extern  uint8_t *src;
extern int src_stride;
extern uint8_t *dst;
extern int dst_stride;
extern int width;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < width; i += 4) {
    uint8_t *s0 = src + 0 * src_stride;
    uint8_t *s1 = src + 1 * src_stride;
    
    // Process two groups of 2x2 pixels per iteration, doubling throughput
    // First 2x2 block
    dst[0*dst_stride + 0*3 + 2] = dst[0*dst_stride + 1*3 + 2] = 
    dst[1*dst_stride + 1*3 + 2] = dst[1*dst_stride + 0*3 + 2] = (((const union unaligned_16 *)(s0 + 2*1))->l) >> 8;
    
    dst[0*dst_stride + 1*3 + 1] = (((const union unaligned_16 *)(s0 + 2*1))->l + ((const union unaligned_16 *)(s1 + 2*0))->l) >> 9;
    dst[1*dst_stride + 0*3 + 1] = (((const union unaligned_16 *)(s1 + 2*0))->l) >> 8;
    dst[0*dst_stride + 0*3 + 1] = dst[1*dst_stride + 1*3 + 1] = (((const union unaligned_16 *)(s0 + 2*1))->l + ((const union unaligned_16 *)(s1 + 2*0))->l) >> 9;
    
    dst[1*dst_stride + 1*3 + 0] = dst[0*dst_stride + 0*3 + 0] = 
    dst[0*dst_stride + 1*3 + 0] = dst[1*dst_stride + 0*3 + 0] = (((const union unaligned_16 *)(s0 + 2*0))->l) >> 8;

    // Second 2x2 block at offset +2 in source
    dst[0*dst_stride + 3*3 + 2] = dst[0*dst_stride + 2*3 + 2] = 
    dst[1*dst_stride + 2*3 + 2] = dst[1*dst_stride + 3*3 + 2] = (((const union unaligned_16 *)(s0 + 2*2))->l) >> 8;
    
    dst[0*dst_stride + 2*3 + 1] = (((const union unaligned_16 *)(s0 + 2*2))->l + ((const union unaligned_16 *)(s1 + 2*1))->l) >> 9;
    dst[1*dst_stride + 3*3 + 1] = (((const union unaligned_16 *)(s1 + 2*1))->l) >> 8;
    dst[0*dst_stride + 3*3 + 1] = dst[1*dst_stride + 2*3 + 1] = (((const union unaligned_16 *)(s0 + 2*2))->l + ((const union unaligned_16 *)(s1 + 2*1))->l) >> 9;
    
    dst[1*dst_stride + 2*3 + 0] = dst[0*dst_stride + 3*3 + 0] = 
    dst[0*dst_stride + 2*3 + 0] = dst[1*dst_stride + 3*3 + 0] = (((const union unaligned_16 *)(s0 + 2*1))->l) >> 8;

    src += 4 * 2;
    dst += 12;
}
}
