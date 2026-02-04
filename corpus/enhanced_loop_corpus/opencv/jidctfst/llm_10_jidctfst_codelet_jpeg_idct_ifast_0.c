#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef long JLONG;

typedef JLONG DCTELEM;

typedef short JCOEF;

typedef JCOEF *JCOEFPTR;

typedef JLONG IFAST_MULT_TYPE;

extern DCTELEM tmp0;
extern DCTELEM tmp1;
extern DCTELEM tmp2;
extern DCTELEM tmp3;
extern DCTELEM tmp4;
extern DCTELEM tmp5;
extern DCTELEM tmp6;
extern DCTELEM tmp7;
extern DCTELEM tmp10;
extern DCTELEM tmp11;
extern DCTELEM tmp12;
extern DCTELEM tmp13;
extern DCTELEM z5;
extern DCTELEM z10;
extern DCTELEM z11;
extern DCTELEM z12;
extern DCTELEM z13;
extern JCOEFPTR inptr;
extern IFAST_MULT_TYPE *quantptr;
extern int *wsptr;
extern int ctr;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (ctr = 16; ctr > 0; ctr -= 2) {
    int dcval1, dcval2;
    DCTELEM t0_1, t1_1, t2_1, t3_1, t10_1, t11_1, t12_1, t13_1;
    DCTELEM t4_1, t5_1, t6_1, t7_1, z10_1, z11_1, z12_1, z13_1, z5_1;
    
    // First iteration unrolled and simplified
    if (inptr[8 * 1] == 0 && inptr[8 * 2] == 0 && inptr[8 * 3] == 0 &&
        inptr[8 * 4] == 0 && inptr[8 * 5] == 0 && inptr[8 * 6] == 0 && inptr[8 * 7] == 0) {
        dcval1 = (int)(((inptr[8 * 0]) * (quantptr[8 * 0])) >> (13 - 1));
        for (int k = 0; k < 8; ++k) wsptr[8 * k] = dcval1;
    } else {
        t0_1 = (((inptr[8 * 0]) * (quantptr[8 * 0])) >> (13 - 1));
        t1_1 = (((inptr[8 * 2]) * (quantptr[8 * 2])) >> (13 - 1));
        t2_1 = (((inptr[8 * 4]) * (quantptr[8 * 4])) >> (13 - 1));
        t3_1 = (((inptr[8 * 6]) * (quantptr[8 * 6])) >> (13 - 1));
        t10_1 = t0_1 + t2_1;
        t11_1 = t0_1 - t2_1;
        t13_1 = t1_1 + t3_1;
        t12_1 = ((DCTELEM)(((t1_1 - t3_1) * (((JLONG)362))) >> (8))) - t13_1;
        t0_1 = t10_1 + t13_1;
        t3_1 = t10_1 - t13_1;
        t1_1 = t11_1 + t12_1;
        t2_1 = t11_1 - t12_1;

        t4_1 = (((inptr[8 * 1]) * (quantptr[8 * 1])) >> (13 - 1));
        t5_1 = (((inptr[8 * 3]) * (quantptr[8 * 3])) >> (13 - 1));
        t6_1 = (((inptr[8 * 5]) * (quantptr[8 * 5])) >> (13 - 1));
        t7_1 = (((inptr[8 * 7]) * (quantptr[8 * 7])) >> (13 - 1));
        z13_1 = t6_1 + t5_1;
        z10_1 = t6_1 - t5_1;
        z11_1 = t4_1 + t7_1;
        z12_1 = t4_1 - t7_1;
        t7_1 = z11_1 + z13_1;
        t11_1 = ((DCTELEM)(((z11_1 - z13_1) * (((JLONG)362))) >> (8)));
        z5_1 = ((DCTELEM)(((z10_1 + z12_1) * (((JLONG)473))) >> (8)));
        t10_1 = ((DCTELEM)(((z12_1) * (((JLONG)277))) >> (8))) - z5_1;
        t12_1 = ((DCTELEM)(((z10_1) * (-((JLONG)669))) >> (8))) + z5_1;
        t6_1 = t12_1 - t7_1;
        t5_1 = t11_1 - t6_1;
        t4_1 = t10_1 + t5_1;

        wsptr[8 * 0] = (int)(t0_1 + t7_1);
        wsptr[8 * 7] = (int)(t0_1 - t7_1);
        wsptr[8 * 1] = (int)(t1_1 + t6_1);
        wsptr[8 * 6] = (int)(t1_1 - t6_1);
        wsptr[8 * 2] = (int)(t2_1 + t5_1);
        wsptr[8 * 5] = (int)(t2_1 - t5_1);
        wsptr[8 * 4] = (int)(t3_1 + t4_1);
        wsptr[8 * 3] = (int)(t3_1 - t4_1);
    }

    // Second iteration with offset
    JCOEFPTR inptr2 = inptr + 8;
    IFAST_MULT_TYPE *quantptr2 = quantptr + 8;
    int *wsptr2 = wsptr + 8;

    if (inptr2[8 * 1] == 0 && inptr2[8 * 2] == 0 && inptr2[8 * 3] == 0 &&
        inptr2[8 * 4] == 0 && inptr2[8 * 5] == 0 && inptr2[8 * 6] == 0 && inptr2[8 * 7] == 0) {
        dcval2 = (int)(((inptr2[8 * 0]) * (quantptr2[8 * 0])) >> (13 - 1));
        for (int k = 0; k < 8; ++k) wsptr2[8 * k] = dcval2;
    } else {
        t0_1 = (((inptr2[8 * 0]) * (quantptr2[8 * 0])) >> (13 - 1));
        t1_1 = (((inptr2[8 * 2]) * (quantptr2[8 * 2])) >> (13 - 1));
        t2_1 = (((inptr2[8 * 4]) * (quantptr2[8 * 4])) >> (13 - 1));
        t3_1 = (((inptr2[8 * 6]) * (quantptr2[8 * 6])) >> (13 - 1));
        t10_1 = t0_1 + t2_1;
        t11_1 = t0_1 - t2_1;
        t13_1 = t1_1 + t3_1;
        t12_1 = ((DCTELEM)(((t1_1 - t3_1) * (((JLONG)362))) >> (8))) - t13_1;
        t0_1 = t10_1 + t13_1;
        t3_1 = t10_1 - t13_1;
        t1_1 = t11_1 + t12_1;
        t2_1 = t11_1 - t12_1;

        t4_1 = (((inptr2[8 * 1]) * (quantptr2[8 * 1])) >> (13 - 1));
        t5_1 = (((inptr2[8 * 3]) * (quantptr2[8 * 3])) >> (13 - 1));
        t6_1 = (((inptr2[8 * 5]) * (quantptr2[8 * 5])) >> (13 - 1));
        t7_1 = (((inptr2[8 * 7]) * (quantptr2[8 * 7])) >> (13 - 1));
        z13_1 = t6_1 + t5_1;
        z10_1 = t6_1 - t5_1;
        z11_1 = t4_1 + t7_1;
        z12_1 = t4_1 - t7_1;
        t7_1 = z11_1 + z13_1;
        t11_1 = ((DCTELEM)(((z11_1 - z13_1) * (((JLONG)362))) >> (8)));
        z5_1 = ((DCTELEM)(((z10_1 + z12_1) * (((JLONG)473))) >> (8)));
        t10_1 = ((DCTELEM)(((z12_1) * (((JLONG)277))) >> (8))) - z5_1;
        t12_1 = ((DCTELEM)(((z10_1) * (-((JLONG)669))) >> (8))) + z5_1;
        t6_1 = t12_1 - t7_1;
        t5_1 = t11_1 - t6_1;
        t4_1 = t10_1 + t5_1;

        wsptr2[8 * 0] = (int)(t0_1 + t7_1);
        wsptr2[8 * 7] = (int)(t0_1 - t7_1);
        wsptr2[8 * 1] = (int)(t1_1 + t6_1);
        wsptr2[8 * 6] = (int)(t1_1 - t6_1);
        wsptr2[8 * 2] = (int)(t2_1 + t5_1);
        wsptr2[8 * 5] = (int)(t2_1 - t5_1);
        wsptr2[8 * 4] = (int)(t3_1 + t4_1);
        wsptr2[8 * 3] = (int)(t3_1 - t4_1);
    }

    inptr += 2;
    quantptr += 2;
    wsptr += 2;
}
}
