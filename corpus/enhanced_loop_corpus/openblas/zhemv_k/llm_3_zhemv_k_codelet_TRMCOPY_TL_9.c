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
    // Use strided access by precomputing base pointers and stepping through with fixed increments
    BLASLONG stride_a = lda;
    BLASLONG stride_b = m;
    BLASLONG stride_c = m;

    aa1 = a;
    aa2 = a + stride_a;
    bb1 = b1;
    bb2 = b1 + stride_b;
    cc1 = b2;
    cc2 = b2 + stride_c;

    a += 2 * lda + 2;
    b1 += 2 * m + 2;
    b2 += 2 * m + 2;

    if (m - js >= 2) {
        // Direct assignment using strided pointer arithmetic
        a11 = aa1[0]; a21 = aa1[1];
        a22 = aa2[1];
        bb1[0] = a11; bb1[1] = a21;
        bb2[0] = a21; bb2[1] = a22;

        // Advance pointers by 2 in leading dimension
        aa1 += 2; aa2 += 2;
        bb1 += 2; bb2 += 2;
        cc1 += 2 * stride_c; cc2 += 2 * stride_c;

        // Loop unrolling via counted for-loop with strided accesses for C matrix
        BLASLONG trip_count = (m - js - 2) >> 1;
        for (BLASLONG i = 0; i < trip_count; i++) {
            a11 = *(aa1 + 0); a21 = *(aa1 + 1);
            a12 = *(aa2 + 0); a22 = *(aa2 + 1);

            // Store into B: row-wise, adjacent elements
            *(bb1 + 0) = a11; *(bb1 + 1) = a21;
            *(bb2 + 0) = a12; *(bb2 + 1) = a22;

            // Store into C: column-major style with stride m
            *(cc1 + 0) = a11; *(cc1 + 1) = a12;
            *(cc2 + 0) = a21; *(cc2 + 1) = a22;

            // Stride forward
            aa1 += 2; aa2 += 2;
            bb1 += 2; bb2 += 2;
            cc1 += 2 * m; cc2 += 2 * m;
        }

        // Final odd column using strided access
        if ((m - js - 2) & 1) {
            a11 = *(aa1 + 0);
            a12 = *(aa2 + 0);
            *(bb1 + 0) = a11;
            *(bb2 + 0) = a12;
            *(cc1 + 0) = a11;
            *(cc1 + 1) = a12;
        }
    }

    // Handle single row remainder
    if (m - js == 1) {
        *(bb1 + 0) = *(aa1 + 0);
    }
}
}
