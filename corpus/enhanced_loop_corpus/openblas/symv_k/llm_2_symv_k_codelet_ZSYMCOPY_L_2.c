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
extern float a21;
extern float a31;
extern float a41;
extern float a12;
extern float a22;
extern float a32;
extern float a42;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (js = 0; js < m; js += 2) {
    aa1 = a + 0 * lda;
    aa2 = a + 1 * lda;
    a += 2 * lda + 4;
    bb1 = b1 + 0 * m;
    bb2 = b1 + 2 * m;
    b1 += 4 * m + 4;
    cc1 = b2 + 0 * m;
    cc2 = b2 + 2 * m;
    b2 += 4 * m + 4;

    if (m - js >= 2) {
        float *ptr_aa1 = aa1;
        float *ptr_aa2 = aa2;
        float *ptr_bb1 = bb1;
        float *ptr_bb2 = bb2;
        float *ptr_cc1 = cc1;
        float *ptr_cc2 = cc2;

        a11 = ptr_aa1[0]; a21 = ptr_aa1[1]; a31 = ptr_aa1[2]; a41 = ptr_aa1[3];
        a12 = ptr_aa2[2]; a22 = ptr_aa2[3];

        ptr_bb1[0] = a11; ptr_bb1[1] = a21; ptr_bb1[2] = a31; ptr_bb1[3] = a41;
        ptr_bb2[0] = a31; ptr_bb2[1] = a41; ptr_bb2[2] = a12; ptr_bb2[3] = a22;

        ptr_aa1 += 4; ptr_aa2 += 4;
        ptr_bb1 += 4; ptr_bb2 += 4;
        ptr_cc1 += 4 * m; ptr_cc2 += 4 * m;

        BLASLONG remaining = (m - js - 2) >> 1;
        for (BLASLONG k = 0; k < remaining; k++) {
            a11 = ptr_aa1[0]; a21 = ptr_aa1[1]; a31 = ptr_aa1[2]; a41 = ptr_aa1[3];
            a12 = ptr_aa2[0]; a22 = ptr_aa2[1]; a32 = ptr_aa2[2]; a42 = ptr_aa2[3];

            ptr_bb1[0] = a11; ptr_bb1[1] = a21; ptr_bb1[2] = a31; ptr_bb1[3] = a41;
            ptr_bb2[0] = a12; ptr_bb2[1] = a22; ptr_bb2[2] = a32; ptr_bb2[3] = a42;
            ptr_cc1[0] = a11; ptr_cc1[1] = a21; ptr_cc1[2] = a12; ptr_cc1[3] = a22;
            ptr_cc2[0] = a31; ptr_cc2[1] = a41; ptr_cc2[2] = a32; ptr_cc2[3] = a42;

            ptr_aa1 += 4; ptr_aa2 += 4;
            ptr_bb1 += 4; ptr_bb2 += 4;
            ptr_cc1 += 4 * m; ptr_cc2 += 4 * m;
        }

        if (m & 1) {
            a11 = ptr_aa1[0]; a21 = ptr_aa1[1];
            a12 = ptr_aa2[0]; a22 = ptr_aa2[1];

            ptr_bb1[0] = a11; ptr_bb1[1] = a21;
            ptr_bb2[0] = a12; ptr_bb2[1] = a22;
            ptr_cc1[0] = a11; ptr_cc1[1] = a21; ptr_cc1[2] = a12; ptr_cc1[3] = a22;
        }
    }

    if (m - js == 1) {
        a11 = *(aa1 + 0);
        a21 = *(aa1 + 1);
        *(bb1 + 0) = a11;
        *(bb1 + 1) = a21;
    }
}
}
