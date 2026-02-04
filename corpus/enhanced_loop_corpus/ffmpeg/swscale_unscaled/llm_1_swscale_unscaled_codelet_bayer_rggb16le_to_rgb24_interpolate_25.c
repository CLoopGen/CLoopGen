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
    // Flattened outer loop: Unroll the original loop by a factor of 2 and reduce loop depth
    for (i = 2; i < width - 2; i += 4) { // Step increased to 4 to simulate partial unrolling
        // First iteration of original step (i)
        if (i < width - 2) {
            dst[(0) * dst_stride + (0) * 3 + 2] = ((unsigned int)(((const union unaligned_16 *)(&(src[(-1) * src_stride + 2 * (-1)])))->l) + (unsigned int)(((const union unaligned_16 *)(&(src[(-1) * src_stride + 2 * (1)])))->l) + (unsigned int)(((const union unaligned_16 *)(&(src[(1) * src_stride + 2 * (-1)])))->l) + (unsigned int)(((const union unaligned_16 *)(&(src[(1) * src_stride + 2 * (1)])))->l)) >> (2 + 8);
            dst[(0) * dst_stride + (0) * 3 + 1] = ((unsigned int)(((const union unaligned_16 *)(&(src[(-1) * src_stride + 2 * (0)])))->l) + (unsigned int)(((const union unaligned_16 *)(&(src[(0) * src_stride + 2 * (-1)])))->l) + (unsigned int)(((const union unaligned_16 *)(&(src[(0) * src_stride + 2 * (1)])))->l) + (unsigned int)(((const union unaligned_16 *)(&(src[(1) * src_stride + 2 * (0)])))->l)) >> (2 + 8);
            dst[(0) * dst_stride + (0) * 3 + 0] = (((const union unaligned_16 *)(&(src[(0) * src_stride + 2 * (0)])))->l) >> 8;
            dst[(0) * dst_stride + (1) * 3 + 2] = ((unsigned int)(((const union unaligned_16 *)(&(src[(-1) * src_stride + 2 * (1)])))->l) + (unsigned int)(((const union unaligned_16 *)(&(src[(1) * src_stride + 2 * (1)])))->l)) >> (1 + 8);
            dst[(0) * dst_stride + (1) * 3 + 1] = (((const union unaligned_16 *)(&(src[(0) * src_stride + 2 * (1)])))->l) >> 8;
            dst[(0) * dst_stride + (1) * 3 + 0] = ((unsigned int)(((const union unaligned_16 *)(&(src[(0) * src_stride + 2 * (0)])))->l) + (unsigned int)(((const union unaligned_16 *)(&(src[(0) * src_stride + 2 * (2)])))->l)) >> (1 + 8);
            dst[(1) * dst_stride + (0) * 3 + 2] = ((unsigned int)(((const union unaligned_16 *)(&(src[(1) * src_stride + 2 * (-1)])))->l) + (unsigned int)(((const union unaligned_16 *)(&(src[(1) * src_stride + 2 * (1)])))->l)) >> (1 + 8);
            dst[(1) * dst_stride + (0) * 3 + 1] = (((const union unaligned_16 *)(&(src[(1) * src_stride + 2 * (0)])))->l) >> 8;
            dst[(1) * dst_stride + (0) * 3 + 0] = ((unsigned int)(((const union unaligned_16 *)(&(src[(0) * src_stride + 2 * (0)])))->l) + (unsigned int)(((const union unaligned_16 *)(&(src[(2) * src_stride + 2 * (0)])))->l)) >> (1 + 8);
            dst[(1) * dst_stride + (1) * 3 + 2] = (((const union unaligned_16 *)(&(src[(1) * src_stride + 2 * (1)])))->l) >> 8;
            dst[(1) * dst_stride + (1) * 3 + 1] = ((unsigned int)(((const union unaligned_16 *)(&(src[(0) * src_stride + 2 * (1)])))->l) + (unsigned int)(((const union unaligned_16 *)(&(src[(1) * src_stride + 2 * (0)])))->l) + (unsigned int)(((const union unaligned_16 *)(&(src[(1) * src_stride + 2 * (2)])))->l) + (unsigned int)(((const union unaligned_16 *)(&(src[(2) * src_stride + 2 * (1)])))->l)) >> (2 + 8);
            dst[(1) * dst_stride + (1) * 3 + 0] = ((unsigned int)(((const union unaligned_16 *)(&(src[(0) * src_stride + 2 * (0)])))->l) + (unsigned int)(((const union unaligned_16 *)(&(src[(0) * src_stride + 2 * (2)])))->l) + (unsigned int)(((const union unaligned_16 *)(&(src[(2) * src_stride + 2 * (0)])))->l) + (unsigned int)(((const union unaligned_16 *)(&(src[(2) * src_stride + 2 * (2)])))->l)) >> (2 + 8);
            src += 2 * 2;
            dst += 6;
        }

        // Second "unrolled" iteration (i+2), if valid
        if (i + 2 < width - 2) {
            uint8_t* local_src = src + 2 * 2;
            uint8_t* local_dst = dst + 6;

            local_dst[(0) * dst_stride + (0) * 3 + 2] = ((unsigned int)(((const union unaligned_16 *)(&(local_src[(-1) * src_stride + 2 * (-1)])))->l) + (unsigned int)(((const union unaligned_16 *)(&(local_src[(-1) * src_stride + 2 * (1)])))->l) + (unsigned int)(((const union unaligned_16 *)(&(local_src[(1) * src_stride + 2 * (-1)])))->l) + (unsigned int)(((const union unaligned_16 *)(&(local_src[(1) * src_stride + 2 * (1)])))->l)) >> (2 + 8);
            local_dst[(0) * dst_stride + (0) * 3 + 1] = ((unsigned int)(((const union unaligned_16 *)(&(local_src[(-1) * src_stride + 2 * (0)])))->l) + (unsigned int)(((const union unaligned_16 *)(&(local_src[(0) * src_stride + 2 * (-1)])))->l) + (unsigned int)(((const union unaligned_16 *)(&(local_src[(0) * src_stride + 2 * (1)])))->l) + (unsigned int)(((const union unaligned_16 *)(&(local_src[(1) * src_stride + 2 * (0)])))->l)) >> (2 + 8);
            local_dst[(0) * dst_stride + (0) * 3 + 0] = (((const union unaligned_16 *)(&(local_src[(0) * src_stride + 2 * (0)])))->l) >> 8;
            local_dst[(0) * dst_stride + (1) * 3 + 2] = ((unsigned int)(((const union unaligned_16 *)(&(local_src[(-1) * src_stride + 2 * (1)])))->l) + (unsigned int)(((const union unaligned_16 *)(&(local_src[(1) * src_stride + 2 * (1)])))->l)) >> (1 + 8);
            local_dst[(0) * dst_stride + (1) * 3 + 1] = (((const union unaligned_16 *)(&(local_src[(0) * src_stride + 2 * (1)])))->l) >> 8;
            local_dst[(0) * dst_stride + (1) * 3 + 0] = ((unsigned int)(((const union unaligned_16 *)(&(local_src[(0) * src_stride + 2 * (0)])))->l) + (unsigned int)(((const union unaligned_16 *)(&(local_src[(0) * src_stride + 2 * (2)])))->l)) >> (1 + 8);
            local_dst[(1) * dst_stride + (0) * 3 + 2] = ((unsigned int)(((const union unaligned_16 *)(&(local_src[(1) * src_stride + 2 * (-1)])))->l) + (unsigned int)(((const union unaligned_16 *)(&(local_src[(1) * src_stride + 2 * (1)])))->l)) >> (1 + 8);
            local_dst[(1) * dst_stride + (0) * 3 + 1] = (((const union unaligned_16 *)(&(local_src[(1) * src_stride + 2 * (0)])))->l) >> 8;
            local_dst[(1) * dst_stride + (0) * 3 + 0] = ((unsigned int)(((const union unaligned_16 *)(&(local_src[(0) * src_stride + 2 * (0)])))->l) + (unsigned int)(((const union unaligned_16 *)(&(local_src[(2) * src_stride + 2 * (0)])))->l)) >> (1 + 8);
            local_dst[(1) * dst_stride + (1) * 3 + 2] = (((const union unaligned_16 *)(&(local_src[(1) * src_stride + 2 * (1)])))->l) >> 8;
            local_dst[(1) * dst_stride + (1) * 3 + 1] = ((unsigned int)(((const union unaligned_16 *)(&(local_src[(0) * src_stride + 2 * (1)])))->l) + (unsigned int)(((const union unaligned_16 *)(&(local_src[(1) * src_stride + 2 * (0)])))->l) + (unsigned int)(((const union unaligned_16 *)(&(local_src[(1) * src_stride + 2 * (2)])))->l) + (unsigned int)(((const union unaligned_16 *)(&(local_src[(2) * src_stride + 2 * (1)])))->l)) >> (2 + 8);
            local_dst[(1) * dst_stride + (1) * 3 + 0] = ((unsigned int)(((const union unaligned_16 *)(&(local_src[(0) * src_stride + 2 * (0)])))->l) + (unsigned int)(((const union unaligned_16 *)(&(local_src[(0) * src_stride + 2 * (2)])))->l) + (unsigned int)(((const union unaligned_16 *)(&(local_src[(2) * src_stride + 2 * (0)])))->l) + (unsigned int)(((const union unaligned_16 *)(&(local_src[(2) * src_stride + 2 * (2)])))->l)) >> (2 + 8);
        }
        src += 4 * 2; // Advance source by 4 steps (simulated unrolling)
        dst += 12;   // Advance destination by 12 bytes
    }
}
