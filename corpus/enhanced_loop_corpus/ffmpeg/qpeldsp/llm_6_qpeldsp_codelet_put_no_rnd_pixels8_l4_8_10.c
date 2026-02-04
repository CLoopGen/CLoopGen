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
    uint32_t a1, b1, c1, d1, l0_1, l1_1, h0_1, h1_1;
    uint32_t a2, b2, c2, d2, l0_2, l1_2, h0_2, h1_2;

    a1 = (((const union unaligned_32 *)(&src1[i * src_stride1]))->l);
    b1 = (((const union unaligned_32 *)(&src2[i * src_stride2]))->l);
    c1 = (((const union unaligned_32 *)(&src3[i * src_stride3]))->l);
    d1 = (((const union unaligned_32 *)(&src4[i * src_stride4]))->l);

    a2 = (((const union unaligned_32 *)(&src1[i * src_stride1 + 4]))->l);
    b2 = (((const union unaligned_32 *)(&src2[i * src_stride2 + 4]))->l);
    c2 = (((const union unaligned_32 *)(&src3[i * src_stride3 + 4]))->l);
    d2 = (((const union unaligned_32 *)(&src4[i * src_stride4 + 4]))->l);

    l0_1 = (a1 & 50529027UL) + (b1 & 50529027UL) + 16843009UL;
    h0_1 = ((a1 & 4244438268UL) >> 2) + ((b1 & 4244438268UL) >> 2);
    l1_1 = (c1 & 50529027UL) + (d1 & 50529027UL);
    h1_1 = ((c1 & 4244438268UL) >> 2) + ((d1 & 4244438268UL) >> 2);

    l0_2 = (a2 & 50529027UL) + (b2 & 50529027UL) + 16843009UL;
    h0_2 = ((a2 & 4244438268UL) >> 2) + ((b2 & 4244438268UL) >> 2);
    l1_2 = (c2 & 50529027UL) + (d2 & 50529027UL);
    h1_2 = ((c2 & 4244438268UL) >> 2) + ((d2 & 4244438268UL) >> 2);

    *((uint32_t *)&dst[i * dst_stride]) = h0_1 + h1_1 + (((l0_1 + l1_1) >> 2) & 252645135UL);
    *((uint32_t *)&dst[i * dst_stride + 4]) = h0_2 + h1_2 + (((l0_2 + l1_2) >> 2) & 252645135UL);
}
}
