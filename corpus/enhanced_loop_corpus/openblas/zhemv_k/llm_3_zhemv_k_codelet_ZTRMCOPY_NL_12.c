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



void loop() {
    for (js = 0; js < m; js += 2) {
        // Change memory access pattern to use strided access via index scaling
        BLASLONG offset_a_col = 0;
        BLASLONG offset_b_row = 0;

        aa1 = a;
        aa2 = a + lda;
        bb1 = b1;
        bb2 = b1 + 2 * m;
        cc1 = b2;
        cc2 = b2 + 2 * m;

        a += 2 * lda + 4;
        b1 += 4 * m + 4;
        b2 += 4 * m + 4;

        if (m - js >= 2) {
            // Use explicit indexing with stride to simulate non-unit access
            a11 = aa1[offset_a_col + 0]; a21 = aa1[offset_a_col + 1];
            a31 = aa1[offset_a_col + 2]; a41 = aa1[offset_a_col + 3];
            a12 = aa2[offset_a_col + 2]; a22 = aa2[offset_a_col + 3];

            bb1[offset_b_row + 0] = a11; bb1[offset_b_row + 1] = a21;
            bb1[offset_b_row + 2] = a31; bb1[offset_b_row + 3] = a41;
            bb2[offset_b_row + 0] = a31; bb2[offset_b_row + 1] = a41;
            bb2[offset_b_row + 2] = a12; bb2[offset_b_row + 3] = a22;

            offset_a_col += 4;
            offset_b_row += 4;

            BLASLONG inner_iters = (m - js - 2) >> 1;
            for (is = 0; is < inner_iters; is++) {
                a11 = aa1[offset_a_col + 0]; a21 = aa1[offset_a_col + 1];
                a31 = aa1[offset_a_col + 2]; a41 = aa1[offset_a_col + 3];
                a12 = aa2[offset_a_col + 0]; a22 = aa2[offset_a_col + 1];
                a32 = aa2[offset_a_col + 2]; a42 = aa2[offset_a_col + 3];

                bb1[offset_b_row + 0] = a11; bb1[offset_b_row + 1] = a21;
                bb1[offset_b_row + 2] = a31; bb1[offset_b_row + 3] = a41;
                bb2[offset_b_row + 0] = a12; bb2[offset_b_row + 1] = a22;
                bb2[offset_b_row + 2] = a32; bb2[offset_b_row + 3] = a42;

                cc1[js + 0] = a11; cc1[js + 1] = a21; cc1[js + 2] = a12; cc1[js + 3] = a22;
                cc2[js + 0] = a31; cc2[js + 1] = a41; cc2[js + 2] = a32; cc2[js + 3] = a42;

                offset_a_col += 4;
                offset_b_row += 4;
            }

            if (m & 1) {
                a11 = aa1[offset_a_col + 0]; a21 = aa1[offset_a_col + 1];
                a12 = aa2[offset_a_col + 0]; a22 = aa2[offset_a_col + 1];

                bb1[offset_b_row + 0] = a11; bb1[offset_b_row + 1] = a21;
                bb2[offset_b_row + 0] = a12; bb2[offset_b_row + 1] = a22;

                cc1[js + 0] = a11; cc1[js + 1] = a21;
                cc1[js + 2] = a12; cc1[js + 3] = a22;
            }
        }

        if (m - js == 1) {
            a11 = aa1[0]; a21 = aa1[1];
            bb1[0] = a11; bb1[1] = a21;
        }
    }
}
