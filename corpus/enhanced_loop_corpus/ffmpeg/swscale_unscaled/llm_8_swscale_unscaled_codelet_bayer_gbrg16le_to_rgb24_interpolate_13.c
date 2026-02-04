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
for (i = 2; i < width - 2; i += 4) {
    // Unroll loop by factor of 2 to increase computational intensity
    int j;
    for (j = 0; j < 2 && (i + j*2) < width - 2; ++j) {
        int dst_offset = j * 6;
        int src_offset = j * 4;

        dst[dst_offset + 0] = ((unsigned int)(((const union unaligned_16 *)(&(src[(-1) * src_stride])))->l) + 
                               (unsigned int)(((const union unaligned_16 *)(&(src[(1) * src_stride])))->l)) >> 9;
        dst[dst_offset + 1] = (((const union unaligned_16 *)(&(src[(0) * src_stride])))->l) >> 8;
        dst[dst_offset + 2] = ((unsigned int)(((const union unaligned_16 *)(&(src[2 * (-1)])))->l) + 
                               (unsigned int)(((const union unaligned_16 *)(&(src[2 * (1)])))->l)) >> 9;

        dst[dst_offset + 3] = ((unsigned int)(((const union unaligned_16 *)(&(src[(-1) * src_stride])))->l) + 
                              (unsigned int)(((const union unaligned_16 *)(&(src[(-1) * src_stride + 4])))->l) + 
                              (unsigned int)(((const union unaligned_16 *)(&(src[(1) * src_stride])))->l) + 
                              (unsigned int)(((const union unaligned_16 *)(&(src[(1) * src_stride + 4])))->l)) >> 10;
        dst[dst_offset + 4] = ((unsigned int)(((const union unaligned_16 *)(&(src[(-1) * src_stride + 2])))->l) + 
                              (unsigned int)(((const union unaligned_16 *)(&(src[(0) * src_stride])))->l) + 
                              (unsigned int)(((const union unaligned_16 *)(&(src[(0) * src_stride + 4])))->l) + 
                              (unsigned int)(((const union unaligned_16 *)(&(src[(1) * src_stride + 2])))->l)) >> 10;
        dst[dst_offset + 5] = (((const union unaligned_16 *)(&(src[(0) * src_stride + 2])))->l) >> 8;

        src += 4;
        dst += 6;
    }
}
}
