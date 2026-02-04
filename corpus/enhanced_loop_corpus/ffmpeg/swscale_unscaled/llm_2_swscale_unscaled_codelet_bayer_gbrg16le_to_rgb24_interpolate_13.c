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
for (i = 2; i < width - 2; i += 2) {
    int src_offset = (-1) * src_stride;
    int dst_base = 0;
    uint8_t* src_ptr = src;
    uint8_t* dst_ptr = dst;

    dst_ptr[dst_base + 0] = ((unsigned int)(((const union unaligned_16 *)(&(src_ptr[src_offset + 0])))->l) + 
                             (unsigned int)(((const union unaligned_16 *)(&(src_ptr[src_offset + 4])))->l)) >> 9;
    dst_ptr[dst_base + 1] = (((const union unaligned_16 *)(&(src_ptr[0])))->l) >> 8;
    dst_ptr[dst_base + 2] = ((unsigned int)(((const union unaligned_16 *)(&(src_ptr[-2])))->l) + 
                             (unsigned int)(((const union unaligned_16 *)(&(src_ptr[2])))->l)) >> 9;

    dst_base += 3;
    dst_ptr += dst_stride;

    dst_ptr[0] = ((unsigned int)(((const union unaligned_16 *)(&(src_ptr[src_offset + 0])))->l) + 
                  (unsigned int)(((const union unaligned_16 *)(&(src_ptr[src_offset + 4])))->l) +
                  (unsigned int)(((const union unaligned_16 *)(&(src_ptr[src_stride + 0])))->l) +
                  (unsigned int)(((const union unaligned_16 *)(&(src_ptr[src_stride + 4])))->l)) >> 10;
    dst_ptr[1] = ((unsigned int)(((const union unaligned_16 *)(&(src_ptr[src_offset + 2])))->l) + 
                  (unsigned int)(((const union unaligned_16 *)(&(src_ptr[0])))->l) +
                  (unsigned int)(((const union unaligned_16 *)(&(src_ptr[4])))->l) +
                  (unsigned int)(((const union unaligned_16 *)(&(src_ptr[src_stride + 2])))->l)) >> 10;
    dst_ptr[2] = (((const union unaligned_16 *)(&(src_ptr[2])))->l) >> 8;

    src_ptr += src_stride;
    dst_ptr += dst_stride;
    dst_base = 0;

    dst_ptr[dst_base + 0] = (((const union unaligned_16 *)(&(src_ptr[0])))->l) >> 8;
    dst_ptr[dst_base + 1] = ((unsigned int)(((const union unaligned_16 *)(&(src_ptr[-src_stride])))->l) + 
                             (unsigned int)(((const union unaligned_16 *)(&(src_ptr[-1])))->l) +
                             (unsigned int)(((const union unaligned_16 *)(&(src_ptr[1])))->l) +
                             (unsigned int)(((const union unaligned_16 *)(&(src_ptr[src_stride])))->l)) >> 10;
    dst_ptr[dst_base + 2] = ((unsigned int)(((const union unaligned_16 *)(&(src_ptr[-src_stride -1])))->l) + 
                             (unsigned int)(((const union unaligned_16 *)(&(src_ptr[-src_stride +1])))->l) +
                             (unsigned int)(((const union unaligned_16 *)(&(src_ptr[src_stride -1])))->l) +
                             (unsigned int)(((const union unaligned_16 *)(&(src_ptr[src_stride +1])))->l)) >> 10;

    dst_base += 3;
    dst_ptr += dst_stride;

    dst_ptr[0] = ((unsigned int)(((const union unaligned_16 *)(&(src_ptr[0])))->l) + 
                  (unsigned int)(((const union unaligned_16 *)(&(src_ptr[4])))->l)) >> 9;
    dst_ptr[1] = (((const union unaligned_16 *)(&(src_ptr[2])))->l) >> 8;
    dst_ptr[2] = ((unsigned int)(((const union unaligned_16 *)(&(src_ptr[-src_stride +2])))->l) + 
                  (unsigned int)(((const union unaligned_16 *)(&(src_ptr[src_stride +2])))->l)) >> 9;

    src += 4;
    dst += 6;
}
}
