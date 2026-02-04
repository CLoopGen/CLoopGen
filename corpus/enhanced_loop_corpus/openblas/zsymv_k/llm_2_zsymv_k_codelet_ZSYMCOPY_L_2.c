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
        float *ptr_a1 = aa1;
        float *ptr_a2 = aa2;
        float *ptr_b1 = bb1;
        float *ptr_b2 = bb2;
        float *ptr_c1 = cc1;
        float *ptr_c2 = cc2;

        a11 = ptr_a1[0]; a21 = ptr_a1[1]; a31 = ptr_a1[2]; a41 = ptr_a1[3];
        a12 = ptr_a2[2]; a22 = ptr_a2[3];

        ptr_b1[0] = a11; ptr_b1[1] = a21; ptr_b1[2] = a31; ptr_b1[3] = a41;
        ptr_b2[0] = a31; ptr_b2[1] = a41; ptr_b2[2] = a12; ptr_b2[3] = a22;

        ptr_a1 += 4; ptr_a2 += 4;
        ptr_b1 += 4; ptr_b2 += 4;
        ptr_c1 += 4 * m; ptr_c2 += 4 * m;

        BLASLONG remaining = (m - js - 2) >> 1;
        for (BLASLONG i = 0; i < remaining; i++) {
            a11 = ptr_a1[0]; a21 = ptr_a1[1]; a31 = ptr_a1[2]; a41 = ptr_a1[3];
            a12 = ptr_a2[0]; a22 = ptr_a2[1]; a32 = ptr_a2[2]; a42 = ptr_a2[3];

            ptr_b1[0] = a11; ptr_b1[1] = a21; ptr_b1[2] = a31; ptr_b1[3] = a41;
            ptr_b2[0] = a12; ptr_b2[1] = a22; ptr_b2[2] = a32; ptr_b2[3] = a42;
            ptr_c1[0] = a11; ptr_c1[1] = a21; ptr_c1[2] = a12; ptr_c1[3] = a22;
            ptr_c2[0] = a31; ptr_c2[1] = a41; ptr_c2[2] = a32; ptr_c2[3] = a42;

            ptr_a1 += 4; ptr_a2 += 4;
            ptr_b1 += 4; ptr_b2 += 4;
            ptr_c1 += 4 * m; ptr_c2 += 4 * m;
        }

        if (m & 1) {
            a11 = ptr_a1[0]; a21 = ptr_a1[1];
            a12 = ptr_a2[0]; a22 = ptr_a2[1];

            ptr_b1[0] = a11; ptr_b1[1] = a21;
            ptr_b2[0] = a12; ptr_b2[1] = a22;
            ptr_c1[0] = a11; ptr_c1[1] = a21; ptr_c1[2] = a12; ptr_c1[3] = a22;
        }
    }

    if (m - js == 1) {
        a11 = *(aa1 + 0); a21 = *(aa1 + 1);
        *(bb1 + 0) = a11; *(bb1 + 1) = a21;
    }
}
}
