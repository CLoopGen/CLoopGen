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
// Strided access with reverse loop order (still using for)
// Access every second row in a strided pattern, stepping by 2*i but reading adjacent elements
int step = 2;
for (i = 0; i < h; i += step) {
    if (i + 1 >= h) break; // Ensure we don't go out of bounds

    uint32_t a, b, c, d, l0, l1, h0, h1;
    // Use non-linear index mapping: access i and i+1 in a staggered way
    int base_indices[2] = {i, i + 1};
    for (int j = 0; j < 2; j++) {
        int idx = base_indices[j];
        int s1_off = idx * src_stride1;
        int s2_off = idx * src_stride2;
        int s3_off = idx * src_stride3;
        int s4_off = idx * src_stride4;
        int dst_off = idx * dst_stride;

        a = ((const union unaligned_32 *)&src1[s1_off])->l;
        b = ((const union unaligned_32 *)&src2[s2_off])->l;
        c = ((const union unaligned_32 *)&src3[s3_off])->l;
        d = ((const union unaligned_32 *)&src4[s4_off])->l;
        l0 = (a & 50529027UL) + (b & 50529027UL) + 33686018UL;
        h0 = ((a & 4244438268UL) >> 2) + ((b & 4244438268UL) >> 2);
        l1 = (c & 50529027UL) + (d & 50529027UL);
        h1 = ((c & 4244438268UL) >> 2) + ((d & 4244438268UL) >> 2);
        ((uint32_t *)&dst[dst_off])[0] = h0 + h1 + (((l0 + l1) >> 2) & 252645135UL);

        a = ((const union unaligned_32 *)&src1[s1_off + 4])->l;
        b = ((const union unaligned_32 *)&src2[s2_off + 4])->l;
        c = ((const union unaligned_32 *)&src3[s3_off + 4])->l;
        d = ((const union unaligned_32 *)&src4[s4_off + 4])->l;
        l0 = (a & 50529027UL) + (b & 50529027UL) + 33686018UL;
        h0 = ((a & 4244438268UL) >> 2) + ((b & 4244438268UL) >> 2);
        l1 = (c & 50529027UL) + (d & 50529027UL);
        h1 = ((c & 4244438268UL) >> 2) + ((d & 4244438268UL) >> 2);
        ((uint32_t *)&dst[dst_off])[1] = h0 + h1 + (((l0 + l1) >> 2) & 252645135UL);
    }
}
}
