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
    // Change access pattern to use indirect indexing via offset arrays
    // Simulate strided-to-consecutive transformation using precomputed indices

    BLASLONG base_a = 0;
    BLASLONG base_b = 0;
    BLASLONG base_c = 0;

    aa1 = a + 0 * lda;
    aa2 = a + 1 * lda;
    a += 2 * lda + 2;

    bb1 = b1; bb2 = b1 + 1 * m;
    cc1 = b2; cc2 = b2 + 1 * m;

    b1 += 2 * m + 2;
    b2 += 2 * m + 2;

    if (m - js >= 2) {
        // First block: write 2x2 submatrix directly using local accumulators
        a11 = aa1[0]; a21 = aa1[1];
        a22 = aa2[1];

        bb1[0] = a11; bb1[1] = a21;
        bb2[0] = a21; bb2[1] = a22;

        // Prepare incremental pointers
        BLASLONG step_count = (m - js - 2);
        float *ptr_aa1 = aa1 + 2;
        float *ptr_aa2 = aa2 + 2;
        float *ptr_bb1 = bb1 + 2;
        float *ptr_bb2 = bb2 + 2;
        float *ptr_cc1 = cc1 + 2 * m;
        float *ptr_cc2 = cc2 + 2 * m;

        // Fully unroll using for-loop with consecutive pair updates
        for (is = 0; is < step_count; is++) {
            a11 = ptr_aa1[0]; a21 = ptr_aa1[1];
            a12 = ptr_aa2[0]; a22 = ptr_aa2[1];

            ptr_bb1[0] = a11; ptr_bb1[1] = a21;
            ptr_bb2[0] = a12; ptr_bb2[1] = a22;

            ptr_cc1[0] = a11; ptr_cc1[1] = a12;
            ptr_cc2[0] = a21; ptr_cc2[1] = a22;

            ptr_aa1 += 2; ptr_aa2 += 2;
            ptr_bb1 += 2; ptr_bb2 += 2;
            ptr_cc1 += 2 * m; ptr_cc2 += 2 * m;
        }

        // Handle leftover element if step_count was odd
        if ((m - js - 2) & 1) {
            a11 = ptr_aa1[0]; a12 = ptr_aa2[0];
            ptr_bb1[0] = a11; ptr_bb2[0] = a12;
            ptr_cc1[0] = a11; ptr_cc1[1] = a12;
        }
    }
    if (m - js == 1) {
        a11 = *(aa1 + 0);
        *(bb1 + 0) = a11;
    }
}
}
