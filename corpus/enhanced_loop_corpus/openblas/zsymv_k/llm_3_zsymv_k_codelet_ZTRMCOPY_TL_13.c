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
        float temp_A[8]; 
        float temp_B[8]; 
        float temp_C[8]; 

        temp_A[0] = *(aa1 + 0);
        temp_A[1] = *(aa1 + 1);
        temp_A[2] = *(aa1 + 2);
        temp_A[3] = *(aa1 + 3);
        temp_A[4] = *(aa2 + 2);
        temp_A[5] = *(aa2 + 3);

        *(bb1 + 0) = temp_A[0];
        *(bb1 + 1) = temp_A[1];
        *(bb1 + 2) = temp_A[2];
        *(bb1 + 3) = temp_A[3];
        *(bb2 + 0) = temp_A[2];
        *(bb2 + 1) = temp_A[3];
        *(bb2 + 2) = temp_A[4];
        *(bb2 + 3) = temp_A[5];

        aa1 += 4;
        aa2 += 4;
        bb1 += 4;
        bb2 += 4;
        cc1 += 4 * m;
        cc2 += 4 * m;

        BLASLONG unroll_factor = (m - js - 2) >> 1;
        for (BLASLONG k = 0; k < unroll_factor; ++k) {
            temp_A[0] = aa1[0]; temp_A[1] = aa1[1]; temp_A[2] = aa1[2]; temp_A[3] = aa1[3];
            temp_A[4] = aa2[0]; temp_A[5] = aa2[1]; temp_A[6] = aa2[2]; temp_A[7] = aa2[3];

            bb1[0] = temp_A[0]; bb1[1] = temp_A[1]; bb1[2] = temp_A[2]; bb1[3] = temp_A[3];
            bb2[0] = temp_A[4]; bb2[1] = temp_A[5]; bb2[2] = temp_A[6]; bb2[3] = temp_A[7];
            cc1[0] = temp_A[0]; cc1[1] = temp_A[1]; cc1[2] = temp_A[4]; cc1[3] = temp_A[5];
            cc2[0] = temp_A[2]; cc2[1] = temp_A[3]; cc2[2] = temp_A[6]; cc2[3] = temp_A[7];

            aa1 += 4;
            aa2 += 4;
            bb1 += 4;
            bb2 += 4;
            cc1 += 4 * m;
            cc2 += 4 * m;
        }

        if (m & 1) {
            temp_B[0] = *(aa1 + 0); temp_B[1] = *(aa1 + 1);
            temp_B[2] = *(aa2 + 0); temp_B[3] = *(aa2 + 1);

            *(bb1 + 0) = temp_B[0]; *(bb1 + 1) = temp_B[1];
            *(bb2 + 0) = temp_B[2]; *(bb2 + 1) = temp_B[3];
            *(cc1 + 0) = temp_B[0]; *(cc1 + 1) = temp_B[1];
            *(cc1 + 2) = temp_B[2]; *(cc1 + 3) = temp_B[3];
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
