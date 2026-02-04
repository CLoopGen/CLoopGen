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
        // Change memory access pattern to use strided access via index arithmetic
        BLASLONG offset_a_col = 0;
        BLASLONG offset_b_block = 0;

        if (m - js >= 2) {
            // Load initial values using explicit strided addressing
            a11 = *(a + offset_a_col + 0 * lda);
            a21 = *(a + offset_a_col + 1 * lda);
            a31 = *(a + offset_a_col + 2 * lda);
            a41 = *(a + offset_a_col + 3 * lda);
            a12 = *(a + (offset_a_col + 2) + 1 * lda);
            a22 = *(a + (offset_a_col + 3) + 1 * lda);

            // Write to B and C blocks with fixed stride patterns
            *(b1 + 0 * m + 0) = a11;
            *(b1 + 0 * m + 1) = a21;
            *(b1 + 0 * m + 2) = a31;
            *(b1 + 0 * m + 3) = a41;
            *(b1 + 2 * m + 0) = a31;
            *(b1 + 2 * m + 1) = a41;
            *(b1 + 2 * m + 2) = a12;
            *(b1 + 2 * m + 3) = a22;

            offset_a_col += 4;
            offset_b_block += 4;

            BLASLONG iterations = (m - js - 2) >> 1;
            for (is = 0; is < iterations; is++) {
                // Strided reads from 'a' with increasing column offset
                a11 = *(a + offset_a_col + 0 * lda);
                a21 = *(a + offset_a_col + 1 * lda);
                a31 = *(a + offset_a_col + 2 * lda);
                a41 = *(a + offset_a_col + 3 * lda);
                a12 = *(a + offset_a_col + 0 * lda + lda);
                a22 = *(a + offset_a_col + 1 * lda + lda);
                a32 = *(a + offset_a_col + 2 * lda + lda);
                a42 = *(a + offset_a_col + 3 * lda + lda);

                // Write to multiple destinations using calculated indices
                *(b1 + offset_b_block + 0 * m + 0) = a11;
                *(b1 + offset_b_block + 0 * m + 1) = a21;
                *(b1 + offset_b_block + 0 * m + 2) = a31;
                *(b1 + offset_b_block + 0 * m + 3) = a41;
                *(b1 + offset_b_block + 2 * m + 0) = a12;
                *(b1 + offset_b_block + 2 * m + 1) = a22;
                *(b1 + offset_b_block + 2 * m + 2) = a32;
                *(b1 + offset_b_block + 2 * m + 3) = a42;

                *(b2 + offset_b_block + 0 * m + 0) = a11;
                *(b2 + offset_b_block + 0 * m + 1) = a21;
                *(b2 + offset_b_block + 2 * m + 0) = a12;
                *(b2 + offset_b_block + 2 * m + 1) = a22;
                *(b2 + offset_b_block + 0 * m + 2) = a12;
                *(b2 + offset_b_block + 0 * m + 3) = a22;
                *(b2 + offset_b_block + 2 * m + 2) = a32;
                *(b2 + offset_b_block + 2 * m + 3) = a42;

                offset_a_col += 4;
                offset_b_block += 4;
            }

            if (m & 1) {
                a11 = *(a + offset_a_col + 0 * lda);
                a21 = *(a + offset_a_col + 1 * lda);
                a12 = *(a + offset_a_col + 0 * lda + lda);
                a22 = *(a + offset_a_col + 1 * lda + lda);

                *(b1 + offset_b_block + 0 * m + 0) = a11;
                *(b1 + offset_b_block + 0 * m + 1) = a21;
                *(b1 + offset_b_block + 2 * m + 0) = a12;
                *(b1 + offset_b_block + 2 * m + 1) = a22;

                *(b2 + offset_b_block + 0 * m + 0) = a11;
                *(b2 + offset_b_block + 0 * m + 1) = a21;
                *(b2 + offset_b_block + 0 * m + 2) = a12;
                *(b2 + offset_b_block + 0 * m + 3) = a22;
            }
        }

        if (m - js == 1) {
            a11 = *(a + 0 * lda);
            a21 = *(a + 1 * lda);
            *(b1 + 0 * m) = a11;
            *(b1 + 0 * m + 1) = a21;
        }

        // Update base pointers as in original
        a += 2 * lda + 4;
        b1 += 4 * m + 4;
        b2 += 4 * m + 4;
    }
}
