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
    // Change memory access pattern to indirect via pointer arrays to simulate irregular/strided access
    // Precompute source and destination pointers for each accessed location

    uint8_t *src_ptrs[12];
    uint8_t *dst_ptrs[12];

    // Source address setup (indirect access)
    src_ptrs[0] = &(src[(-1) * src_stride + 2 * 0]);     // (-1,0)
    src_ptrs[1] = &(src[(1) * src_stride + 2 * 0]);      // (1,0)
    src_ptrs[2] = &(src[(0) * src_stride + 2 * 0]);      // (0,0)
    src_ptrs[3] = &(src[(0) * src_stride + 2 * (-1)]);   // (0,-1)
    src_ptrs[4] = &(src[(0) * src_stride + 2 * 1]);      // (0,1)
    src_ptrs[5] = &(src[(-1) * src_stride + 2 * 2]);    // (-1,2)
    src_ptrs[6] = &(src[(1) * src_stride + 2 * 2]);     // (1,2)
    src_ptrs[7] = &(src[(-1) * src_stride + 2 * 1]);    // (-1,1)
    src_ptrs[8] = &(src[(0) * src_stride + 2 * 2]);     // (0,2)
    src_ptrs[9] = &(src[(1) * src_stride + 2 * (-1)]);  // (1,-1)
    src_ptrs[10] = &(src[(2) * src_stride + 2 * 0]);   // (2,0)
    src_ptrs[11] = &(src[(2) * src_stride + 2 * (-1)]); // (2,-1)

    // Destination address setup (indirect access)
    dst_ptrs[0] = &(dst[(0) * dst_stride + (0) * 3 + 2]);
    dst_ptrs[1] = &(dst[(0) * dst_stride + (0) * 3 + 1]);
    dst_ptrs[2] = &(dst[(0) * dst_stride + (0) * 3 + 0]);
    dst_ptrs[3] = &(dst[(0) * dst_stride + (1) * 3 + 2]);
    dst_ptrs[4] = &(dst[(0) * dst_stride + (1) * 3 + 1]);
    dst_ptrs[5] = &(dst[(0) * dst_stride + (1) * 3 + 0]);
    dst_ptrs[6] = &(dst[(1) * dst_stride + (0) * 3 + 2]);
    dst_ptrs[7] = &(dst[(1) * dst_stride + (0) * 3 + 1]);
    dst_ptrs[8] = &(dst[(1) * dst_stride + (0) * 3 + 0]);
    dst_ptrs[9] = &(dst[(1) * dst_stride + (1) * 3 + 2]);
    dst_ptrs[10] = &(dst[(1) * dst_stride + (1) * 3 + 1]);
    dst_ptrs[11] = &(dst[(1) * dst_stride + (1) * 3 + 0]);

    // Use indirect access via pointer array
    *dst_ptrs[0] = ((unsigned int)(((const union unaligned_16 *)(src_ptrs[0]))->l) + 
                    (unsigned int)(((const union unaligned_16 *)(src_ptrs[1]))->l)) >> (1 + 8);
    *dst_ptrs[1] = (((const union unaligned_16 *)(src_ptrs[2]))->l) >> 8;
    *dst_ptrs[2] = ((unsigned int)(((const union unaligned_16 *)(src_ptrs[3]))->l) + 
                    (unsigned int)(((const union unaligned_16 *)(src_ptrs[4]))->l)) >> (1 + 8);

    *dst_ptrs[3] = ((unsigned int)(((const union unaligned_16 *)(src_ptrs[0]))->l) + 
                    (unsigned int)(((const union unaligned_16 *)(src_ptrs[5]))->l) + 
                    (unsigned int)(((const union unaligned_16 *)(src_ptrs[1]))->l) + 
                    (unsigned int)(((const union unaligned_16 *)(src_ptrs[6]))->l)) >> (2 + 8);
    *dst_ptrs[4] = ((unsigned int)(((const union unaligned_16 *)(src_ptrs[7]))->l) + 
                    (unsigned int)(((const union unaligned_16 *)(src_ptrs[2]))->l) + 
                    (unsigned int)(((const union unaligned_16 *)(src_ptrs[8]))->l) + 
                    (unsigned int)(((const union unaligned_16 *)(src_ptrs[4]))->l)) >> (2 + 8);
    *dst_ptrs[5] = (((const union unaligned_16 *)(src_ptrs[4]))->l) >> 8;

    *dst_ptrs[6] = (((const union unaligned_16 *)(src_ptrs[1]))->l) >> 8;
    *dst_ptrs[7] = ((unsigned int)(((const union unaligned_16 *)(src_ptrs[2]))->l) + 
                    (unsigned int)(((const union unaligned_16 *)(src_ptrs[9]))->l) + 
                    (unsigned int)(((const union unaligned_16 *)(src_ptrs[4]))->l) + 
                    (unsigned int)(((const union unaligned_16 *)(src_ptrs[10]))->l)) >> (2 + 8);
    *dst_ptrs[8] = ((unsigned int)(((const union unaligned_16 *)(src_ptrs[3]))->l) + 
                    (unsigned int)(((const union unaligned_16 *)(src_ptrs[4]))->l) + 
                    (unsigned int)(((const union unaligned_16 *)(src_ptrs[11]))->l) + 
                    (unsigned int)(((const union unaligned_16 *)(src_ptrs[4]+(2*src_stride))))->l) >> (2 + 8);  // (2,1) = (0,1) + 2*src_stride

    *dst_ptrs[9] = ((unsigned int)(((const union unaligned_16 *)(src_ptrs[1]))->l) + 
                    (unsigned int)(((const union unaligned_16 *)(src_ptrs[6]))->l)) >> (1 + 8);
    *dst_ptrs[10] = (((const union unaligned_16 *)(src_ptrs[4]+src_stride))->l) >> 8;  // (1,1) = (0,1) + src_stride
    *dst_ptrs[11] = ((unsigned int)(((const union unaligned_16 *)(src_ptrs[4]))->l) + 
                     (unsigned int)(((const union unaligned_16 *)(src_ptrs[4]+2*src_stride))->l)) >> (1 + 8);  // (0,1) and (2,1)

    src += 2 * 2;
    dst += 6;
}
}
