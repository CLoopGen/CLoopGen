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
        // Change memory access to use base offsets with precomputed strides (consecutive block layout simulation)
        BLASLONG offset_a_col = js;
        BLASLONG offset_b_row = js * 2;

        if (m - js >= 2) {
            // Directly compute all required source and destination bases
            a11 = a[offset_a_col + 0 * lda]; a21 = a[offset_a_col + 1 * lda];
            a31 = a[offset_a_col + 2 * lda]; a41 = a[offset_a_col + 3 * lda];
            a12 = a[offset_a_col + 2 * lda + 1]; a22 = a[offset_a_col + 3 * lda + 1];

            // Write to B1 with consecutive storage (transpose-like scatter-gather)
            b1[offset_b_row + 0] = a11; b1[offset_b_row + 1] = a21;
            b1[offset_b_row + 2] = a31; b1[offset_b_row + 3] = a41;
            b1[offset_b_row + 4] = a31; b1[offset_b_row + 5] = a41;
            b1[offset_b_row + 6] = a12; b1[offset_b_row + 7] = a22;

            // Initialize C blocks using row-major addressing with stride
            BLASLONG c_offset_1 = offset_b_row * m;
            BLASLONG c_offset_2 = (offset_b_row + 2) * m;

            b2[c_offset_1 + 0] = a11; b2[c_offset_1 + 1] = a21;
            b2[c_offset_1 + m + 0] = a12; b2[c_offset_1 + m + 1] = a22;

            b2[c_offset_2 + 0] = a31; b2[c_offset_2 + 1] = a41;
            b2[c_offset_2 + m + 0] = a32; b2[c_offset_2 + m + 1] = a42;

            // Main loop: unrolled iterations using direct indexing (avoiding pointer arithmetic)
            BLASLONG i;
            for (i = 2; i < m - 1; i += 2) {
                BLASLONG idx_a_next = (i + offset_a_col);
                a11 = a[idx_a_next + 0 * lda]; a21 = a[idx_a_next + 1 * lda];
                a31 = a[idx_a_next + 2 * lda]; a41 = a[idx_a_next + 3 * lda];
                a12 = a[idx_a_next + 0 * lda + 1]; a22 = a[idx_a_next + 1 * lda + 1];
                a32 = a[idx_a_next + 2 * lda + 1]; a42 = a[idx_a_next + 3 * lda + 1];

                BLASLONG dest_b1 = (i >> 1) * 8 + offset_b_row;
                b1[dest_b1 + 0] = a11; b1[dest_b1 + 1] = a21; b1[dest_b1 + 2] = a31; b1[dest_b1 + 3] = a41;
                b1[dest_b1 + 4] = a12; b1[dest_b1 + 5] = a22; b1[dest_b1 + 6] = a32; b1[dest_b1 + 7] = a42;

                BLASLONG dest_c1 = (i >> 1) * 4 + c_offset_1;
                BLASLONG dest_c2 = (i >> 1) * 4 + c_offset_2;

                b2[dest_c1 + 0] = a11; b2[dest_c1 + 1] = a21; b2[dest_c1 + m + 0] = a12; b2[dest_c1 + m + 1] = a22;
                b2[dest_c2 + 0] = a31; b2[dest_c2 + 1] = a41; b2[dest_c2 + m + 0] = a32; b2[dest_c2 + m + 1] = a42;
            }

            // Handle odd-sized tail
            if (m & 1) {
                BLASLONG rem = m - 1;
                a11 = a[rem + 0 * lda]; a21 = a[rem + 1 * lda];
                a12 = a[rem + 0 * lda + 1]; a22 = a[rem + 1 * lda + 1];

                BLASLONG rb1 = ((rem - js) >> 1) * 8 + offset_b_row;
                b1[rb1 + 0] = a11; b1[rb1 + 1] = a21;
                b1[rb1 + 4] = a12; b1[rb1 + 5] = a22;

                BLASLONG rc1 = ((rem - js) >> 1) * 4 + c_offset_1;
                b2[rc1 + 0] = a11; b2[rc1 + 1] = a21;
                b2[rc1 + m + 0] = a12; b2[rc1 + m + 1] = a22;
            }
        }

        // Handle last single column case
        if (m - js == 1) {
            BLASLONG col = js;
            a11 = a[col + 0 * lda]; a21 = a[col + 1 * lda];
            b1[js * 2 + 0] = a11; b1[js * 2 + 1] = a21;
        }
    }
}
