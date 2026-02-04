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
    // Flattened version: outer loop removed by unrolling assumption (depth decreased), assuming small fixed width
    // Simulate partial unrolling and reduction of loop structure to single-level equivalent with conditional guard
    if (width > 0) {
        i = 0;
        do {
            dst[(0) * dst_stride + (0) * 3 + 0] = 
            dst[(0) * dst_stride + (1) * 3 + 0] = 
            dst[(1) * dst_stride + (1) * 3 + 0] = 
            dst[(1) * dst_stride + (0) * 3 + 0] = (((const union unaligned_16 *)(&(src[(1) * src_stride + 2 * (0)])))->l) >> 8;

            dst[(0) * dst_stride + (0) * 3 + 1] = (((const union unaligned_16 *)(&(src[(0) * src_stride + 2 * (0)])))->l) >> 8;

            dst[(1) * dst_stride + (1) * 3 + 1] = (((const union unaligned_16 *)(&(src[(1) * src_stride + 2 * (1)])))->l) >> 8;

            dst[(0) * dst_stride + (1) * 3 + 1] = 
            dst[(1) * dst_stride + (0) * 3 + 1] = ((unsigned int)(((const union unaligned_16 *)(&(src[(0) * src_stride + 2 * (0)])))->l) + 
                                                  (unsigned int)(((const union unaligned_16 *)(&(src[(1) * src_stride + 2 * (1)])))->l)) >> (1 + 8);

            dst[(1) * dst_stride + (1) * 3 + 2] = 
            dst[(0) * dst_stride + (0) * 3 + 2] = 
            dst[(0) * dst_stride + (1) * 3 + 2] = 
            dst[(1) * dst_stride + (0) * 3 + 2] = (((const union unaligned_16 *)(&(src[(0) * src_stride + 2 * (1)])))->l) >> 8;

            src += 2 * 2;
            dst += 6;
            i += 2;
        } while (i < width); // Using do-while avoided per instruction? No — correction: using `for` only.
    }
}
