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
    // Change memory access pattern: use strided access via index scaling instead of pointer arithmetic
    BLASLONG base_a_col = js;
    BLASLONG base_b_row = js * 2;

    if (m - js >= 2) {
        // First block using scaled indices (strided access across matrices)
        a11 = a[0 * lda + base_a_col];
        a31 = a[0 * lda + base_a_col + 2];
        a41 = a[0 * lda + base_a_col + 3];
        a12 = a[1 * lda + base_a_col + 2];

        b1[base_b_row + 0] = a11;
        b1[base_b_row + 1] = 0.0f;
        b1[base_b_row + 2] = a31;
        b1[base_b_row + 3] = -a41;
        b1[base_b_row + 4] = a31;
        b1[base_b_row + 5] = a41;
        b1[base_b_row + 6] = a12;
        b1[base_b_row + 7] = 0.0f;

        // Inner loop using direct index computation (eliminate while with for)
        BLASLONG inner_iters = (m - js - 2) >> 1;
        for (BLASLONG k = 1; k <= inner_iters; k++) {
            BLASLONG col_idx = base_a_col + 2 * k;
            BLASLONG b_offset = base_b_row + 8 * k;
            BLASLONG c_offset_1 = (col_idx >> 1) * m;  // Simulate cc1 row placement
            BLASLONG c_offset_2 = c_offset_1 + 2 * m;

            a11 = a[0 * lda + col_idx + 0];
            a21 = a[0 * lda + col_idx + 1];
            a31 = a[0 * lda + col_idx + 2];
            a41 = a[0 * lda + col_idx + 3];
            a12 = a[1 * lda + col_idx + 0];
            a22 = a[1 * lda + col_idx + 1];
            a32 = a[1 * lda + col_idx + 2];
            a42 = a[1 * lda + col_idx + 3];

            // Store into b1 and b2 using computed offsets (strided in storage, linear in access)
            b1[b_offset + 0] = a11;
            b1[b_offset + 1] = -a21;
            b1[b_offset + 2] = a31;
            b1[b_offset + 3] = -a41;
            b1[b_offset + 4] = a12;
            b1[b_offset + 5] = -a22;
            b1[b_offset + 6] = a32;
            b1[b_offset + 7] = -a42;

            // Store into b2 (as c blocks) using indirect row-major indexing
            b2[c_offset_1 + 0] = a11;
            b2[c_offset_1 + 1] = a21;
            b2[c_offset_1 + 2] = a12;
            b2[c_offset_1 + 3] = a22;
            b2[c_offset_2 + 0] = a31;
            b2[c_offset_2 + 1] = a41;
            b2[c_offset_2 + 2] = a32;
            b2[c_offset_2 + 3] = a42;
        }

        if (m & 1) {
            BLASLONG col_idx = base_a_col + 2 * inner_iters + 0;
            BLASLONG b_offset = base_b_row + 8 * inner_iters;
            BLASLONG c_offset_1 = ((col_idx) >> 1) * m;

            a11 = a[0 * lda + col_idx];
            a21 = a[0 * lda + col_idx + 1];
            a12 = a[1 * lda + col_idx];
            a22 = a[1 * lda + col_idx + 1];

            b1[b_offset + 0] = a11;
            b1[b_offset + 1] = -a21;
            b1[b_offset + 4] = a12;
            b1[b_offset + 5] = -a22;

            b2[c_offset_1 + 0] = a11;
            b2[c_offset_1 + 1] = a21;
            b2[c_offset_1 + 2] = a12;
            b2[c_offset_1 + 3] = a22;
        }
    }

    if (m - js == 1) {
        BLASLONG col_idx = base_a_col;
        BLASLONG b_offset = base_b_row;
        b1[b_offset + 0] = a[0 * lda + col_idx];
        b1[b_offset + 1] = 0.0f;
    }
}
}
