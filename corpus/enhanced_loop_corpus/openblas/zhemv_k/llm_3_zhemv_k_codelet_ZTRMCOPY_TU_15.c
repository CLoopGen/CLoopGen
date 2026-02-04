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
    // Use array-of-pointers style access simulation via base offsets
    BLASLONG offset_a_col = js;
    BLASLONG offset_b_row = 0;

    if (m - js >= 2) {
        for (is = 0; is < js; is += 2) {
            // Consecutive memory access through precomputed indices (flatten 2D access)
            BLASLONG idx_a = offset_a_col + is;
            BLASLONG idx_b = offset_b_row + is;

            // Load 4x2 block using flattened indexing with constant strides
            a11 = a[idx_a + 0*lda]; a21 = a[idx_a + 1*lda];
            a31 = a[idx_a + 2*lda]; a41 = a[idx_a + 3*lda];

            a12 = a[idx_a + 1 + 0*lda]; a22 = a[idx_a + 1 + 1*lda];
            a32 = a[idx_a + 1 + 2*lda]; a42 = a[idx_a + 1 + 3*lda];

            // Write to b1 with linear index progression (consecutive layout assumed)
            b1[idx_b + 0] = a11; b1[idx_b + 1] = a21;
            b1[idx_b + 2] = a31; b1[idx_b + 3] = a41;

            b1[idx_b + 2*m + 0] = a12; b1[idx_b + 2*m + 1] = a22;
            b1[idx_b + 2*m + 2] = a32; b1[idx_b + 2*m + 3] = a42;

            // Store transposed sub-block directly into b2 using calculated indices
            b2[(idx_b/2)*2 + 0] = a11; b2[(idx_b/2)*2 + 1] = a21;
            b2[(idx_b/2)*2 + m*2 + 0] = a12; b2[(idx_b/2)*2 + m*2 + 1] = a22;

            b2[(idx_b/2)*2 + 1] = a31; b2[(idx_b/2)*2 + 1 + m*2] = a41;
            b2[(idx_b/2)*2 + m*2 + 1] = a32; b2[(idx_b/2)*2 + m*2 + 1 + m*2] = a42;

            // Simulate blocked traversal without updating pointers, just index math
        }

        // Handle final 2x4 block using flat indexing
        a11 = a[offset_a_col + 0*lda];     a21 = a[offset_a_col + 1*lda];
        a12 = a[offset_a_col + 1 + 0*lda]; a22 = a[offset_a_col + 1 + 1*lda];
        a32 = a[offset_a_col + 1 + 2*lda]; a42 = a[offset_a_col + 1 + 3*lda];

        BLASLONG final_b_idx = offset_b_row + js - (js > 0 ? 2 : 0); // Approximate last position
        b1[final_b_idx + 0] = a11; b1[final_b_idx + 1] = a21;
        b1[final_b_idx + 2] = a12; b1[final_b_idx + 3] = a22;

        b1[final_b_idx + 2*m + 0] = a12; b1[final_b_idx + 2*m + 1] = a22;
        b1[final_b_idx + 2*m + 2] = a32; b1[final_b_idx + 2*m + 3] = a42;
    }
    if (m - js == 1) {
        for (is = 0; is < js; is += 2) {
            BLASLONG idx = offset_a_col + is;
            a11 = a[idx + 0*lda]; a21 = a[idx + 1*lda];
            a31 = a[idx + 2*lda]; a41 = a[idx + 3*lda];

            b1[is + 0] = a11; b1[is + 1] = a21; b1[is + 2] = a31; b1[is + 3] = a41;

            // Column-wise output in b2 using indirect mapping
            b2[is]           = a11; b2[is + m*2]     = a21;
            b2[is + 1]       = a31; b2[is + 1 + m*2] = a41;
        }
        a11 = a[js]; a21 = a[js + lda];
        b1[js] = a11; b1[js + 1] = a21;
    }
}
}
