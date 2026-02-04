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
        float *aa1_ptr = aa1;
        float *aa2_ptr = aa2;
        float *bb1_ptr = bb1;
        float *bb2_ptr = bb2;
        float *cc1_ptr = cc1;
        float *cc2_ptr = cc2;

        a11 = aa1_ptr[0];
        a21 = aa1_ptr[1];
        a31 = aa1_ptr[2];
        a41 = aa1_ptr[3];
        a12 = aa2_ptr[2];
        a22 = aa2_ptr[3];

        bb1_ptr[0] = a11;
        bb1_ptr[1] = a21;
        bb1_ptr[2] = a31;
        bb1_ptr[3] = a41;
        bb2_ptr[0] = a31;
        bb2_ptr[1] = a41;
        bb2_ptr[2] = a12;
        bb2_ptr[3] = a22;

        aa1_ptr += 4;
        aa2_ptr += 4;
        bb1_ptr += 4;
        bb2_ptr += 4;
        cc1_ptr += 4 * m;
        cc2_ptr += 4 * m;

        BLASLONG remaining = (m - js - 2) >> 1;
        for (BLASLONG k = 0; k < remaining; k++) {
            a11 = aa1_ptr[0];
            a21 = aa1_ptr[1];
            a31 = aa1_ptr[2];
            a41 = aa1_ptr[3];
            a12 = aa2_ptr[0];
            a22 = aa2_ptr[1];
            a32 = aa2_ptr[2];
            a42 = aa2_ptr[3];

            bb1_ptr[0] = a11;
            bb1_ptr[1] = a21;
            bb1_ptr[2] = a31;
            bb1_ptr[3] = a41;
            bb2_ptr[0] = a12;
            bb2_ptr[1] = a22;
            bb2_ptr[2] = a32;
            bb2_ptr[3] = a42;
            cc1_ptr[0] = a11;
            cc1_ptr[1] = a21;
            cc1_ptr[2] = a12;
            cc1_ptr[3] = a22;
            cc2_ptr[0] = a31;
            cc2_ptr[1] = a41;
            cc2_ptr[2] = a32;
            cc2_ptr[3] = a42;

            aa1_ptr += 4;
            aa2_ptr += 4;
            bb1_ptr += 4;
            bb2_ptr += 4;
            cc1_ptr += 4 * m;
            cc2_ptr += 4 * m;
        }

        if (m & 1) {
            a11 = aa1_ptr[0];
            a21 = aa1_ptr[1];
            a12 = aa2_ptr[0];
            a22 = aa2_ptr[1];

            bb1_ptr[0] = a11;
            bb1_ptr[1] = a21;
            bb2_ptr[0] = a12;
            bb2_ptr[1] = a22;
            cc1_ptr[0] = a11;
            cc1_ptr[1] = a21;
            cc1_ptr[2] = a12;
            cc1_ptr[3] = a22;
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
