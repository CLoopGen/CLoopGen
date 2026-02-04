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
    BLASLONG offset_a_col0 = 0 * lda;
    BLASLONG offset_a_col1 = 1 * lda;
    BLASLONG offset_b1_row0 = 0 * m;
    BLASLONG offset_b1_row2 = 2 * m;
    BLASLONG offset_b2_row0 = 0 * m;
    BLASLONG offset_b2_row2 = 2 * m;

    aa1 = a + offset_a_col0;
    aa2 = a + offset_a_col1;
    a += 2 * lda + 4;

    bb1 = b1 + offset_b1_row0;
    bb2 = b1 + offset_b1_row2;
    b1 += 4 * m + 4;

    cc1 = b2 + offset_b2_row0;
    cc2 = b2 + offset_b2_row2;
    b2 += 4 * m + 4;

    if (m - js >= 2) {
        a11 = aa1[0];
        a31 = aa1[2];
        a41 = aa1[3];
        a12 = aa2[2];

        bb1[0] = a11;
        bb1[1] = 0.0f;
        bb1[2] = a31;
        bb1[3] = -a41;
        bb2[0] = a31;
        bb2[1] = a41;
        bb2[2] = a12;
        bb2[3] = 0.0f;

        BLASLONG inner_iters = (m - js - 2) >> 1;
        for (BLASLONG i = 0; i < inner_iters; ++i) {
            BLASLONG base_idx_a = 4 * (i + 1);
            BLASLONG base_idx_b = 4 * (i + 1);
            BLASLONG base_idx_c = 4 * m * (i + 1);

            a11 = aa1[base_idx_a + 0];
            a21 = aa1[base_idx_a + 1];
            a31 = aa1[base_idx_a + 2];
            a41 = aa1[base_idx_a + 3];
            a12 = aa2[base_idx_a + 0];
            a22 = aa2[base_idx_a + 1];
            a32 = aa2[base_idx_a + 2];
            a42 = aa2[base_idx_a + 3];

            bb1[base_idx_b + 0] = a11;
            bb1[base_idx_b + 1] = -a21;
            bb1[base_idx_b + 2] = a31;
            bb1[base_idx_b + 3] = -a41;
            bb2[base_idx_b + 0] = a12;
            bb2[base_idx_b + 1] = -a22;
            bb2[base_idx_b + 2] = a32;
            bb2[base_idx_b + 3] = -a42;

            cc1[base_idx_c + 0] = a11;
            cc1[base_idx_c + 1] = a21;
            cc1[base_idx_c + 2] = a12;
            cc1[base_idx_c + 3] = a22;
            cc2[base_idx_c + 0] = a31;
            cc2[base_idx_c + 1] = a41;
            cc2[base_idx_c + 2] = a32;
            cc2[base_idx_c + 3] = a42;
        }

        if (m & 1) {
            a11 = aa1[4 * inner_iters + 0];
            a21 = aa1[4 * inner_iters + 1];
            a12 = aa2[4 * inner_iters + 0];
            a22 = aa2[4 * inner_iters + 1];

            bb1[4 * inner_iters + 0] = a11;
            bb1[4 * inner_iters + 1] = -a21;
            bb2[4 * inner_iters + 0] = a12;
            bb2[4 * inner_iters + 1] = -a22;

            cc1[4 * m * inner_iters + 0] = a11;
            cc1[4 * m * inner_iters + 1] = a21;
            cc1[4 * m * inner_iters + 2] = a12;
            cc1[4 * m * inner_iters + 3] = a22;
        }
    }

    if (m - js == 1) {
        a11 = aa1[0];
        bb1[0] = a11;
        bb1[1] = 0.0f;
    }
}
}
