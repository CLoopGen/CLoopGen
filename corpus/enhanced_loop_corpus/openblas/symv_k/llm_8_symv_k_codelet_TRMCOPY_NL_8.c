#include <stdio.h>

typedef long BLASLONG;

extern BLASLONG m;
extern float *a;
extern BLASLONG lda;
extern BLASLONG is;
extern BLASLONG js;
extern float *aa1;
extern float *aa2;
extern float *b1;
extern float *b2;
extern float *bb1;
extern float *bb2;
extern float *cc1;
extern float *cc2;
extern float a11;
extern float a12;
extern float a21;
extern float a22;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (js = 0; js < m; js += 4) {
    aa1 = a + 0 * lda;
    aa2 = a + 1 * lda;
    a += 4 * lda + 4;
    bb1 = b1 + 0 * m;
    bb2 = b1 + 1 * m;
    b1 += 4 * m + 4;
    cc1 = b2 + 0 * m;
    cc2 = b2 + 1 * m;
    b2 += 4 * m + 4;

    BLASLONG remaining = m - js;

    if (remaining >= 4) {
        // Unroll by 4: process 4x4 block
        for (is = 0; is < 2; is++) {
            float *local_aa1 = aa1 + is * 2;
            float *local_aa2 = aa2 + is * 2;
            float *local_bb1 = bb1 + is * 2;
            float *local_bb2 = bb2 + is * 2;
            float *local_cc1 = cc1 + is * 2 * m;
            float *local_cc2 = cc2 + is * 2 * m;

            a11 = *(local_aa1 + 0);
            a21 = *(local_aa1 + 1);
            a12 = *(local_aa2 + 0);
            a22 = *(local_aa2 + 1);

            *(local_bb1 + 0) = a11;
            *(local_bb1 + 1) = a21;
            *(local_bb2 + 0) = a12;
            *(local_bb2 + 1) = a22;
            *(local_cc1 + 0) = a11;
            *(local_cc1 + 1) = a12;
            *(local_cc2 + 0) = a21;
            *(local_cc2 + 1) = a22;
        }

        // Inner unrolled loop over remaining columns, step by 4
        for (is = 2; is < (m - js - 2) / 2 + 2; is++) {
            float *local_aa1 = aa1 + is * 2;
            float *local_aa2 = aa2 + is * 2;
            float *local_bb1 = bb1 + is * 2;
            float *local_bb2 = bb2 + is * 2;
            float *local_cc1 = cc1 + is * 2 * m;
            float *local_cc2 = cc2 + is * 2 * m;

            a11 = *(local_aa1 + 0);
            a21 = *(local_aa1 + 1);
            a12 = *(local_aa2 + 0);
            a22 = *(local_aa2 + 1);

            *(local_bb1 + 0) = a11;
            *(local_bb1 + 1) = a21;
            *(local_bb2 + 0) = a12;
            *(local_bb2 + 1) = a22;
            *(local_cc1 + 0) = a11;
            *(local_cc1 + 1) = a12;
            *(local_cc2 + 0) = a21;
            *(local_cc2 + 1) = a22;
        }
    } else if (remaining >= 2) {
        a11 = *(aa1 + 0);
        a21 = *(aa1 + 1);
        a22 = *(aa2 + 1);
        *(bb1 + 0) = a11;
        *(bb1 + 1) = a21;
        *(bb2 + 0) = a21;
        *(bb2 + 1) = a22;
    }

    if (remaining == 1) {
        a11 = *(a - 4 * lda - 4 + 0 * lda + 0);
        *(b1 - 4 * m - 4 + 0 * m + 0) = a11;
    }
}
}
