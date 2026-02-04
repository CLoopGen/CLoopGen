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
    // Use base indices and scale offsets instead of pointer arithmetic
    BLASLONG base_a_col = js;
    BLASLONG base_b_row = js;

    if (m - js >= 2) {
        // Access via calculated linear indices – converting strided to indirect indexing
        BLASLONG idx_a_00 = 0 * lda + base_a_col;
        BLASLONG idx_a_10 = 1 * lda + base_a_col;
        a11 = a[idx_a_00 + 0]; a21 = a[idx_a_00 + 1];
        a22 = a[idx_a_10 + 1];

        BLASLONG idx_b_00 = 0 * m + base_b_row;
        BLASLONG idx_b_10 = 1 * m + base_b_row;
        b1[idx_b_00 + 0] = a11; b1[idx_b_00 + 1] = a21;
        b1[idx_b_10 + 0] = a21; b1[idx_b_10 + 1] = a22;

        // Update for next block using index strides
        BLASLONG offset = 2;
        BLASLONG total_steps = (m - js - 2);

        for (BLASLONG step = 0; step < total_steps; step += 2) {
            BLASLONG pos_a = base_a_col + 2 + step;
            BLASLONG aoff1 = 0 * lda + pos_a;
            BLASLONG aoff2 = 1 * lda + pos_a;

            a11 = a[aoff1 + 0]; a21 = a[aoff1 + 1];
            a12 = a[aoff2 + 0]; a22 = a[aoff2 + 1];

            BLASLONG boff1 = base_b_row + 2 + step;
            BLASLONG boff_b1_0 = 0 * m + boff1;
            BLASLONG boff_b1_1 = 1 * m + boff1;
            b1[boff_b1_0 + 0] = a11; b1[boff_b1_0 + 1] = a21;
            b1[boff_b1_1 + 0] = a12; b1[boff_b1_1 + 1] = a22;

            BLASLONG boff_b2_0 = 0 * m + boff1;
            BLASLONG boff_b2_1 = 1 * m + boff1;
            b2[boff_b2_0 + 0] = a11; b2[boff_b2_0 + 1] = a12;
            b2[boff_b2_1 + 0] = a21; b2[boff_b2_1 + 1] = a22;
        }

        // Handle odd leftover element
        if (total_steps & 1) {
            BLASLONG rem = base_a_col + 2 + total_steps - 1;
            a11 = a[0 * lda + rem];
            a12 = a[1 * lda + rem];

            BLASLONG out_b = base_b_row + 2 + total_steps - 1;
            b1[0 * m + out_b] = a11;
            b1[1 * m + out_b] = a12;

            b2[0 * m + out_b] = a11;
            b2[1 * m + out_b] = a12;
        }
    }

    // Handle last single row/column if m is odd
    if (m - js == 1) {
        a11 = a[0 * lda + js];
        b1[0 * m + js] = a11;
    }
}
}
