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
    aa1 = a + 0 * lda;
    aa2 = a + 1 * lda;
    a += 2 * lda;
    bb1 = b1 + 0 * m;
    bb2 = b1 + 2 * m;
    b1 += 4 * m;
    cc1 = b2 + 0 * m;
    cc2 = b2 + 2 * m;
    b2 += 4;
    if (m - js >= 2) {
        for (is = 0; is < js; is += 2) {
            // Use consecutive pointer dereferencing with array-style access
            float *ptr_a1 = &aa1[0];
            float *ptr_a2 = &aa2[0];
            a11 = ptr_a1[0]; a21 = ptr_a1[1]; a31 = ptr_a1[2]; a41 = ptr_a1[3];
            a12 = ptr_a2[0]; a22 = ptr_a2[1]; a32 = ptr_a2[2]; a42 = ptr_a2[3];
            aa1 += 4;
            aa2 += 4;

            // Write to b-blocks using base+offset indexing in a flat pattern
            float *dest_b1 = &bb1[0], *dest_b2 = &bb2[0];
            dest_b1[0] = a11;     dest_b1[1] = -a21;   dest_b1[2] = a31;     dest_b1[3] = -a41;
            dest_b2[0] = a12;     dest_b2[1] = -a22;   dest_b2[2] = a32;     dest_b2[3] = -a42;

            // Interleave c-block updates with transposed storage via direct indexing
            int stride_c = 4 * m;
            cc1[0*m + 0] = a11; cc1[0*m + 1] = a21;
            cc1[1*m + 0] = a12; cc1[1*m + 1] = a22;
            cc2[0*m + 0] = a31; cc2[0*m + 1] = a41;
            cc2[1*m + 0] = a32; cc2[1*m + 1] = a42;

            bb1 += 4;
            bb2 += 4;
            cc1 += stride_c;
            cc2 += stride_c;
        }
        a11 = aa1[0]; a12 = aa2[0]; a22 = aa2[1]; a32 = aa2[2];
        bb1[0] = a11; bb1[1] = 0.0f; bb1[2] = a12; bb1[3] = a22;
        bb2[0] = a12; bb2[1] = -a22; bb2[2] = a32; bb2[3] = 0.0f;
    }
    if (m - js == 1) {
        for (is = 0; is < js; is += 2) {
            a11 = aa1[0]; a21 = aa1[1]; a31 = aa1[2]; a41 = aa1[3];
            aa1 += 4;
            bb1[0] = a11; bb1[1] = -a21; bb1[2] = a31; bb1[3] = -a41;
            cc1[0] = a11; cc1[1] = a21;
            cc2[0] = a31; cc2[1] = a41;
            bb1 += 4;
            cc1 += 4 * m;
            cc2 += 4 * m;
        }
        a11 = aa1[0];
        bb1[0] = a11; bb1[1] = 0.0f;
    }
}
}
