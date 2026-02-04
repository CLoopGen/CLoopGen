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
for (i = 0; i < h; i += 2) {
    uint32_t a, b, c, d, l0, l1, h0, h1;
    for (int j = 0; j < 2; j++) {
        int idx = i + j;
        if (idx >= h) break;
        a = (((const union unaligned_32 *)(&src1[idx * src_stride1]))->l);
        b = (((const union unaligned_32 *)(&src2[idx * src_stride2]))->l);
        c = (((const union unaligned_32 *)(&src3[idx * src_stride3]))->l);
        d = (((const union unaligned_32 *)(&src4[idx * src_stride4]))->l);
        l0 = (a & 50529027UL) + (b & 50529027UL) + 16843009UL;
        h0 = ((a & 4244438268UL) >> 2) + ((b & 4244438268UL) >> 2);
        l1 = (c & 50529027UL) + (d & 50529027UL);
        h1 = ((c & 4244438268UL) >> 2) + ((d & 4244438268UL) >> 2);
        *((uint32_t *)&dst[idx * dst_stride]) = h0 + h1 + (((l0 + l1) >> 2) & 252645135UL);
    }
}
}
