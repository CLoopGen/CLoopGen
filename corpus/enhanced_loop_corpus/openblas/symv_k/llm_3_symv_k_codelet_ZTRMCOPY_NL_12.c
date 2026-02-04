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
    BLASLONG row_offset_a1 = 0 * lda;
    BLASLONG row_offset_a2 = 1 * lda;
    BLASLONG col_offset_b1 = 0;
    BLASLONG col_offset_b2 = 2;

    aa1 = a + row_offset_a1;
    aa2 = a + row_offset_a2;
    a += 2 * lda + 4;

    bb1 = b1 + col_offset_b1 * m;
    bb2 = b1 + col_offset_b2 * m;
    b1 += 4 * m + 4;

    cc1 = b2 + col_offset_b1 * m;
    cc2 = b2 + col_offset_b2 * m;
    b2 += 4 * m + 4;

    if (m - js >= 2) {
        float temp_reg[8];
        temp_reg[0] = *(aa1 + 0); temp_reg[1] = *(aa1 + 1);
        temp_reg[2] = *(aa1 + 2); temp_reg[3] = *(aa1 + 3);
        temp_reg[4] = *(aa2 + 2); temp_reg[5] = *(aa2 + 3);

        *(bb1 + 0) = temp_reg[0]; *(bb1 + 1) = temp_reg[1];
        *(bb1 + 2) = temp_reg[2]; *(bb1 + 3) = temp_reg[3];
        *(bb2 + 0) = temp_reg[2]; *(bb2 + 1) = temp_reg[3];
        *(bb2 + 2) = temp_reg[4]; *(bb2 + 3) = temp_reg[5];

        aa1 += 4; aa2 += 4;
        bb1 += 4; bb2 += 4;
        cc1 += 4 * m; cc2 += 4 * m;

        BLASLONG trip_count = (m - js - 2) >> 1;
        for (is = 0; is < trip_count; ++is) {
            temp_reg[0] = aa1[0]; temp_reg[1] = aa1[1];
            temp_reg[2] = aa1[2]; temp_reg[3] = aa1[3];
            temp_reg[4] = aa2[0]; temp_reg[5] = aa2[1];
            temp_reg[6] = aa2[2]; temp_reg[7] = aa2[3];

            bb1[0] = temp_reg[0]; bb1[1] = temp_reg[1];
            bb1[2] = temp_reg[2]; bb1[3] = temp_reg[3];

            bb2[0] = temp_reg[4]; bb2[1] = temp_reg[5];
            bb2[2] = temp_reg[6]; bb2[3] = temp_reg[7];

            cc1[0] = temp_reg[0]; cc1[1] = temp_reg[1];
            cc1[2] = temp_reg[4]; cc1[3] = temp_reg[5];

            cc2[0] = temp_reg[2]; cc2[1] = temp_reg[3];
            cc2[2] = temp_reg[6]; cc2[3] = temp_reg[7];

            aa1 += 4; aa2 += 4;
            bb1 += 4; bb2 += 4;
            cc1 += 4 * m; cc2 += 4 * m;
        }

        if (m & 1) {
            a11 = aa1[0]; a21 = aa1[1];
            a12 = aa2[0]; a22 = aa2[1];

            bb1[0] = a11; bb1[1] = a21;
            bb2[0] = a12; bb2[1] = a22;

            cc1[0] = a11; cc1[1] = a21;
            cc1[2] = a12; cc1[3] = a22;
        }
    }

    if (m - js == 1) {
        a11 = aa1[0]; a21 = aa1[1];
        bb1[0] = a11; bb1[1] = a21;
    }
}
}
