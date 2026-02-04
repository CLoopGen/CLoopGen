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
    aa1 = a + 0 * lda;
    aa2 = a + 1 * lda;
    a += 2 * lda + 2;
    bb1 = b1 + 0 * m;
    bb2 = b1 + 1 * m;
    b1 += 2 * m + 2;
    cc1 = b2 + 0 * m;
    cc2 = b2 + 1 * m;
    b2 += 2 * m + 2;

    if (m - js >= 2) {
        // First 2x2 block with consecutive memory writes
        a11 = aa1[0];
        a21 = aa1[1];
        a22 = aa2[1];

        // Write symmetric components to b1 using linear indexing
        bb1[0] = a11;
        bb1[1] = a21;
        bb2[0] = a21;
        bb2[1] = a22;

        aa1 += 2;
        aa2 += 2;
        bb1 += 2;
        bb2 += 2;
        cc1 += 2 * m;
        cc2 += 2 * m;

        // Unroll the remaining iterations as a for-loop with stride-2 access pattern
        BLASLONG rem = (m - js - 2) >> 1;
        for (BLASLONG k = 0; k < rem; k++) {
            a11 = aa1[0];
            a21 = aa1[1];
            a12 = aa2[0];
            a22 = aa2[1];

            // Update both output blocks using strided access via precomputed increments
            *(bb1 + 0) = a11;
            *(bb1 + 1) = a21;
            *(bb2 + 0) = a12;
            *(bb2 + 1) = a22;

            *(cc1 + 0) = a11;
            *(cc1 + 1) = a12;
            *(cc2 + 0) = a21;
            *(cc2 + 1) = a22;

            aa1 += 2;
            aa2 += 2;
            bb1 += 2;
            bb2 += 2;
            cc1 += 2 * m;
            cc2 += 2 * m;
        }

        // Handle leftover column if any
        if ((m - js - 2) & 1) {
            a11 = aa1[0];
            a12 = aa2[0];

            bb1[0] = a11;
            bb2[0] = a12;
            cc1[0] = a11;
            cc1[1] = a12;
        }
    }

    // Handle last single row case
    if (m - js == 1) {
        a11 = *(aa1 + 0);
        *(bb1 + 0) = a11;
    }
}
}
