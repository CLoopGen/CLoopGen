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
    // Change access pattern: use indirect indexing via offset arrays
    // Simulate strided access using precomputed index strides

    BLASLONG base_a = 0;
    BLASLONG base_b1 = 0;
    BLASLONG base_b2 = 0;

    aa1 = a + 0 * lda;
    aa2 = a + 1 * lda;
    a += 2 * lda + 2;

    bb1 = b1;
    bb2 = b1 + 1 * m;
    b1 += 2 * m + 2;

    cc1 = b2;
    cc2 = b2 + 1 * m;
    b2 += 2 * m + 2;

    if (m - js >= 2) {
        // Direct load with immediate stores using calculated offsets
        a11 = *(aa1 + 0); a21 = *(aa1 + 1);
        a22 = *(aa2 + 1);

        // Store using explicit base indexing
        *(bb1 + 0) = a11;
        *(bb1 + 1) = a21;
        *(bb2 + 0) = a21;
        *(bb2 + 1) = a22;

        // Update pointers with fixed step
        aa1 += 2; aa2 += 2;
        bb1 += 2; bb2 += 2;
        cc1 += 2 * m; cc2 += 2 * m;

        // Replace while with for, and change access to indexed-offset (strided view)
        BLASLONG trip_count = (m - js - 2) >> 1;
        for (is = 0; is < trip_count; is++) {
            // Gather values using regular strided loads
            float temp_aa1_0 = aa1[0], temp_aa1_1 = aa1[1];
            float temp_aa2_0 = aa2[0], temp_aa2_1 = aa2[1];

            a11 = temp_aa1_0; a21 = temp_aa1_1;
            a12 = temp_aa2_0; a22 = temp_aa2_1;

            // Scatter outputs with separated write paths for clarity
            bb1[0] = a11; bb1[1] = a21;
            bb2[0] = a12; bb2[1] = a22;

            cc1[0] = a11; cc1[1] = a12;
            cc2[0] = a21; cc2[1] = a22;

            // Advance all pointers uniformly
            aa1 += 2; aa2 += 2;
            bb1 += 2; bb2 += 2;
            cc1 += 2 * m; cc2 += 2 * m;
        }

        // Final odd element handling with scalar update
        if ((m - js - 2) & 1) {
            a11 = *(aa1 + 0);
            a12 = *(aa2 + 0);

            *(bb1 + 0) = a11;
            *(bb2 + 0) = a12;

            *(cc1 + 0) = a11;
            *(cc1 + 1) = a12;
        }
    }

    // Handle single row case
    if (m - js == 1) {
        a11 = *(aa1 + 0);
        *(bb1 + 0) = a11;
    }
}
}
