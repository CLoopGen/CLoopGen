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
    for (i = 0; i < h * 2; i++) {
        uint32_t a, b, c, d, l0, l1, h0, h1;
        int row = i / 2;
        int offset = (i % 2) * 4;
        a = (((const union unaligned_32 *)(&src1[row * src_stride1 + offset]))->l);
        b = (((const union unaligned_32 *)(&src2[row * src_stride2 + offset]))->l);
        c = (((const union unaligned_32 *)(&src3[row * src_stride3 + offset]))->l);
        d = (((const union unaligned_32 *)(&src4[row * src_stride4 + offset]))->l);
        l0 = (a & 50529027UL) + (b & 50529027UL) + 33686018UL;
        h0 = ((a & 4244438268UL) >> 2) + ((b & 4244438268UL) >> 2);
        l1 = (c & 50529027UL) + (d & 50529027UL);
        h1 = ((c & 4244438268UL) >> 2) + ((d & 4244438268UL) >> 2);
        *((uint32_t *)&dst[row * dst_stride + offset]) = h0 + h1 + (((l0 + l1) >> 2) & 252645135UL);
    }
}
