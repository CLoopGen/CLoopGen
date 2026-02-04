#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef long JLONG;

typedef JLONG DCTELEM;

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
extern DCTELEM z1;
extern DCTELEM z2;
extern DCTELEM z3;
extern DCTELEM z4;
extern DCTELEM z5;
extern DCTELEM z11;
extern DCTELEM z13;
extern DCTELEM *dataptr;
extern int ctr;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    // Strided memory access: process every second element first, then the odd-offset ones (2-phase strided pattern)
    for (ctr = 0; ctr < 16; ctr++) {
        int effective_ctr = ctr % 8;
        int phase = ctr / 8;
        DCTELEM *strided_dataptr = dataptr + effective_ctr;

        if (phase == 0) {
            // First pass: even indices in zigzag-like order (0,2,4,6,...)
            if (effective_ctr % 2 != 0) continue;
        } else {
            // Second pass: odd indices (1,3,5,7)
            if (effective_ctr % 2 == 0) continue;
        }

        tmp0 = strided_dataptr[0] + strided_dataptr[7];
        tmp7 = strided_dataptr[0] - strided_dataptr[7];
        tmp1 = strided_dataptr[1] + strided_dataptr[6];
        tmp6 = strided_dataptr[1] - strided_dataptr[6];
        tmp2 = strided_dataptr[2] + strided_dataptr[5];
        tmp5 = strided_dataptr[2] - strided_dataptr[5];
        tmp3 = strided_dataptr[3] + strided_dataptr[4];
        tmp4 = strided_dataptr[3] - strided_dataptr[4];
        tmp10 = tmp0 + tmp3;
        tmp13 = tmp0 - tmp3;
        tmp11 = tmp1 + tmp2;
        tmp12 = tmp1 - tmp2;
        strided_dataptr[0] = tmp10 + tmp11;
        strided_dataptr[4] = tmp10 - tmp11;
        z1 = ((DCTELEM)(((tmp12 + tmp13) * (((JLONG)181))) >> (8)));
        strided_dataptr[2] = tmp13 + z1;
        strided_dataptr[6] = tmp13 - z1;
        tmp10 = tmp4 + tmp5;
        tmp11 = tmp5 + tmp6;
        tmp12 = tmp6 + tmp7;
        z5 = ((DCTELEM)(((tmp10 - tmp12) * (((JLONG)98))) >> (8)));
        z2 = ((DCTELEM)(((tmp10) * (((JLONG)139))) >> (8))) + z5;
        z4 = ((DCTELEM)(((tmp12) * (((JLONG)334))) >> (8))) + z5;
        z3 = ((DCTELEM)(((tmp11) * (((JLONG)181))) >> (8)));
        z11 = tmp7 + z3;
        z13 = tmp7 - z3;
        strided_dataptr[5] = z13 + z2;
        strided_dataptr[3] = z13 - z2;
        strided_dataptr[1] = z11 + z4;
        strided_dataptr[7] = z11 - z4;

        if (phase == 1 && effective_ctr == 7) break; // Exit after second phase completes
    }
}
