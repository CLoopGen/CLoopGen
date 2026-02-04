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
for (js = 0; js < m; js += 2) {
    // Change memory access to use base-offset indexing with flattened indices
    // Simulate strided access via index scaling instead of pointer arithmetic

    BLASLONG offset_a_col, offset_b1_row, offset_b2_row;
    BLASLONG idx_aa1, idx_aa2, idx_bb1, idx_bb2, idx_cc1, idx_cc2;

    offset_a_col = js * lda;
    offset_b1_row = js * m;
    offset_b2_row = js * m;

    if (m - js >= 2) {
        // First block: direct assignment using computed indices
        idx_aa1 = offset_a_col + 0;
        idx_aa2 = offset_a_col + lda;

        a11 = a[idx_aa1 + 0]; a21 = a[idx_aa1 + 1];
        a22 = a[idx_aa2 + 1];

        idx_bb1 = offset_b1_row + 0; idx_bb2 = offset_b1_row + 1;
        b1[idx_bb1 + 0] = a11; b1[idx_bb1 + 1] = a21;
        b1[idx_bb2 + 0] = a21; b1[idx_bb2 + 1] = a22;

        // Inner loop using regular for-loop and indirect indexing
        for (is = 1; is < m - js - 1; is++) {
            BLASLONG col_idx = 2 * is;
            idx_aa1 = offset_a_col + col_idx;
            idx_aa2 = offset_a_col + lda + col_idx;

            a11 = a[idx_aa1 + 0]; a21 = a[idx_aa1 + 1];
            a12 = a[idx_aa2 + 0]; a22 = a[idx_aa2 + 1];

            // Update both b1 and b2 using row-major indexing
            idx_bb1 = offset_b1_row + 0 + 2 * is;
            idx_bb2 = offset_b1_row + 1 + 2 * is;
            b1[idx_bb1 + 0] = a11; b1[idx_bb1 + 1] = a21;
            b1[idx_bb2 + 0] = a12; b1[idx_bb2 + 1] = a22;

            idx_cc1 = offset_b2_row + 0 + 2 * is;
            idx_cc2 = offset_b2_row + 1 + 2 * is;
            b2[idx_cc1 + 0] = a11; b2[idx_cc1 + 1] = a12;
            b2[idx_cc2 + 0] = a21; b2[idx_cc2 + 1] = a22;
        }

        // Final odd column
        if ((m - js) % 2 == 0 && (m - js - 2) % 2 == 1) {
            BLASLONG col_idx = 2 * (m - js - 1);
            a11 = a[offset_a_col + col_idx + 0];
            a12 = a[offset_a_col + lda + col_idx + 0];

            b1[offset_b1_row + 2*(m-js-1)] = a11;
            b1[offset_b1_row + 2*(m-js-1) + m] = a12;
            b2[offset_b2_row + 2*(m-js-1)] = a11;
            b2[offset_b2_row + 2*(m-js-1) + 1] = a12;
        }
    }

    // Handle last single row
    if (m - js == 1) {
        a11 = a[js * lda];
        b1[js * m] = a11;
    }
}
}
