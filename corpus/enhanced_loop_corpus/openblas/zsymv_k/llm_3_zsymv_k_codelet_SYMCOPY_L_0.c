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
    // Use base offsets and scale indices instead of pointer arithmetic
    BLASLONG offset_a_col = 0;
    BLASLONG offset_b_row = 0;

    if (m - js >= 2) {
        // Direct indexed access with fixed strides: treat matrices as row-major packed
        for (BLASLONG j = js; j < js + 2; ++j) {
            for (BLASLONG i = 0; i < 2; ++i) {
                float val = (*(a + i * lda + offset_a_col + j));
                if (i == 0 && j == js) a11 = val;
                if (i == 1 && j == js) a21 = val;
                if (i == 0 && j == js+1) a12 = val;
                if (i == 1 && j == js+1) a22 = val;
            }
        }

        // Write to b1 (symmetric storage, lower triangular) and b2 (transpose in blocks)
        *(b1 + 0*m + offset_b_row + 0) = a11;
        *(b1 + 1*m + offset_b_row + 0) = a21;
        *(b1 + 0*m + offset_b_row + 1) = a21;
        *(b1 + 1*m + offset_b_row + 1) = a22;

        *(b2 + 0*m + offset_b_row + 0) = a11;
        *(b2 + 0*m + offset_b_row + 1) = a12;
        *(b2 + 1*m + offset_b_row + 0) = a21;
        *(b2 + 1*m + offset_b_row + 1) = a22;

        offset_a_col += 2;
        offset_b_row += 2;

        // Middle block: regular update using unit-stride index progression
        for (BLASLONG k = 0; k < (m - js - 2); ++k) {
            a11 = *(a + 0*lda + offset_a_col + 0);
            a21 = *(a + 0*lda + offset_a_col + 1);
            a12 = *(a + 1*lda + offset_a_col + 0);
            a22 = *(a + 1*lda + offset_a_col + 1);

            *(b1 + 0*m + offset_b_row + 0) = a11;
            *(b1 + 0*m + offset_b_row + 1) = a21;
            *(b1 + 1*m + offset_b_row + 0) = a12;
            *(b1 + 1*m + offset_b_row + 1) = a22;

            *(b2 + 0*m + offset_b_row + 0) = a11;
            *(b2 + 0*m + offset_b_row + 1) = a12;
            *(b2 + 1*m + offset_b_row + 0) = a21;
            *(b2 + 1*m + offset_b_row + 1) = a22;

            offset_a_col += 2;
            offset_b_row += 2;
        }

        // Handle leftover column if any
        if ((m - js - 2) & 1) continue; // already handled by loop logic

        // No separate while or do-while — all in for-loops
    }

    // Handle last single row case
    if (m - js == 1) {
        a11 = *(a + 0*lda + js);
        *(b1 + 0*m + js) = a11;
    }
}
}
