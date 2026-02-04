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
    // Change memory access to strided pattern: precompute strides and use scaled indices
    BLASLONG offset_a_col0 = 0, offset_a_col1 = lda;
    BLASLONG offset_b1_block1 = 0, offset_b1_block2 = 2 * m;
    BLASLONG offset_b2_block1 = 0, offset_b2_block2 = 2 * m;
    BLASLONG offset_a_inner = 0, offset_b1_inner = 0, offset_c1_inner = 0, offset_c2_inner = 0;

    if (m - js >= 2) {
        for (is = 0; is < js; is += 2) {
            // Strided access using index scaling instead of pointer arithmetic
            a11 = *(a + offset_a_col0 + offset_a_inner + 0);
            a21 = *(a + offset_a_col0 + offset_a_inner + 1);
            a31 = *(a + offset_a_col0 + offset_a_inner + 2);
            a41 = *(a + offset_a_col0 + offset_a_inner + 3);
            a12 = *(a + offset_a_col1 + offset_a_inner + 0);
            a22 = *(a + offset_a_col1 + offset_a_inner + 1);
            a32 = *(a + offset_a_col1 + offset_a_inner + 2);
            a42 = *(a + offset_a_col1 + offset_a_inner + 3);

            offset_a_inner += 4;

            // Update B blocks using calculated offsets
            *(b1 + offset_b1_block1 + offset_b1_inner + 0) = a11;
            *(b1 + offset_b1_block1 + offset_b1_inner + 1) = -a21;
            *(b1 + offset_b1_block1 + offset_b1_inner + 2) = a31;
            *(b1 + offset_b1_block1 + offset_b1_inner + 3) = -a41;

            *(b1 + offset_b1_block2 + offset_b1_inner + 0) = a12;
            *(b1 + offset_b1_block2 + offset_b1_inner + 1) = -a22;
            *(b1 + offset_b1_block2 + offset_b1_inner + 2) = a32;
            *(b1 + offset_b1_block2 + offset_b1_inner + 3) = -a42;

            offset_b1_inner += 4;

            // Update C blocks with matrix-like indexing (row-major)
            *(b2 + offset_b2_block1 + offset_c1_inner + 0*m + 0) = a11;
            *(b2 + offset_b2_block1 + offset_c1_inner + 0*m + 1) = a21;
            *(b2 + offset_b2_block1 + offset_c1_inner + 1*m + 0) = a12;
            *(b2 + offset_b2_block1 + offset_c1_inner + 1*m + 1) = a22;

            *(b2 + offset_b2_block2 + offset_c2_inner + 0*m + 0) = a31;
            *(b2 + offset_b2_block2 + offset_c2_inner + 0*m + 1) = a41;
            *(b2 + offset_b2_block2 + offset_c2_inner + 1*m + 0) = a32;
            *(b2 + offset_b2_block2 + offset_c2_inner + 1*m + 1) = a42;

            offset_c1_inner += 4 * m;
            offset_c2_inner += 4 * m;
        }
        // Final unrolled write with strided access
        a11 = *(a + offset_a_col0 + offset_a_inner + 0);
        a12 = *(a + offset_a_col1 + offset_a_inner + 0);
        a22 = *(a + offset_a_col1 + offset_a_inner + 1);
        a32 = *(a + offset_a_col1 + offset_a_inner + 2);

        *(b1 + offset_b1_block1 + offset_b1_inner + 0) = a11;
        *(b1 + offset_b1_block1 + offset_b1_inner + 1) = 0.0f;
        *(b1 + offset_b1_block1 + offset_b1_inner + 2) = a12;
        *(b1 + offset_b1_block1 + offset_b1_inner + 3) = a22;

        *(b1 + offset_b1_block2 + offset_b1_inner + 0) = a12;
        *(b1 + offset_b1_block2 + offset_b1_inner + 1) = -a22;
        *(b1 + offset_b1_block2 + offset_b1_inner + 2) = a32;
        *(b1 + offset_b1_block2 + offset_b1_inner + 3) = 0.0f;
    }
    if (m - js == 1) {
        offset_a_inner = 0;
        offset_b1_inner = 0;
        offset_c1_inner = 0;
        offset_c2_inner = 0;
        for (is = 0; is < js; is += 2) {
            a11 = *(a + offset_a_col0 + offset_a_inner + 0);
            a21 = *(a + offset_a_col0 + offset_a_inner + 1);
            a31 = *(a + offset_a_col0 + offset_a_inner + 2);
            a41 = *(a + offset_a_col0 + offset_a_inner + 3);
            offset_a_inner += 4;

            *(b1 + offset_b1_block1 + offset_b1_inner + 0) = a11;
            *(b1 + offset_b1_block1 + offset_b1_inner + 1) = -a21;
            *(b1 + offset_b1_block1 + offset_b1_inner + 2) = a31;
            *(b1 + offset_b1_block1 + offset_b1_inner + 3) = -a41;

            *(b2 + offset_b2_block1 + offset_c1_inner + 0*m + 0) = a11;
            *(b2 + offset_b2_block1 + offset_c1_inner + 0*m + 1) = a21;
            *(b2 + offset_b2_block2 + offset_c2_inner + 0*m + 0) = a31;
            *(b2 + offset_b2_block2 + offset_c2_inner + 0*m + 1) = a41;

            offset_b1_inner += 4;
            offset_c1_inner += 4 * m;
            offset_c2_inner += 4 * m;
        }
        a11 = *(a + offset_a_col0 + 0);
        *(b1 + offset_b1_block1 + 0) = a11;
        *(b1 + offset_b1_block1 + 1) = 0.0f;
    }
    // Advance global pointers after processing block
    a += 2 * lda;
    b1 += 4 * m;
    b2 += 4;
}
}
