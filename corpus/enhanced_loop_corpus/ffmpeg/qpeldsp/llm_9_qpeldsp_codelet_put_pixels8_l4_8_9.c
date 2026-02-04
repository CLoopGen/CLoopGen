#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
union __attribute__((packed)) __attribute__((may_alias)) unaligned_32 {
    uint32_t l;
};


extern uint8_t *dst;
extern  uint8_t *src1;
extern  uint8_t *src2;
extern  uint8_t *src3;
extern  uint8_t *src4;
extern int dst_stride;
extern int src_stride1;
extern int src_stride2;
extern int src_stride3;
extern int src_stride4;
extern int h;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < h; i++) {
    uint32_t a, b, c, d, l0, l1, h0, h1;
    // Load four input values and process with reduced arithmetic depth
    a = (((const union unaligned_32 *)(&src1[i * src_stride1]))->l);
    b = (((const union unaligned_32 *)(&src2[i * src_stride2]))->l);
    c = (((const union unaligned_32 *)(&src3[i * src_stride3]))->l);
    d = (((const union unaligned_32 *)(&src4[i * src_stride4]))->l);

    // Combine all four inputs in one operation with simplified masking
    uint32_t combined_low = (a + b + c + d) & 50529027UL;
    uint32_t combined_high = ((a + b + c + d) & 4244438268UL) >> 2;

    // Reduced computation: single output per row, fewer intermediate variables
    *((uint32_t *)&dst[i * dst_stride]) = combined_high + ((combined_low >> 2) & 252645135UL);
}
}
