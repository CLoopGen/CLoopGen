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
            // Use consecutive memory reads via pointer increments instead of indexing
            float *ptr_a1 = aa1, *ptr_a2 = aa2;
            a11 = *ptr_a1++;
            a21 = *ptr_a1++;
            a31 = *ptr_a1++;
            a41 = *ptr_a1;
            a12 = *ptr_a2++;
            a22 = *ptr_a2++;
            a32 = *ptr_a2++;
            a42 = *ptr_a2;

            // Store to bb1 and bb2 using direct pointer arithmetic
            float *ptr_bb1 = bb1, *ptr_bb2 = bb2;
            *ptr_bb1++ = a11;
            *ptr_bb1++ = a21;
            *ptr_bb1++ = a31;
            *ptr_bb1++ = a41;
            *ptr_bb2++ = a12;
            *ptr_bb2++ = a22;
            *ptr_bb2++ = a32;
            *ptr_bb2++ = a42;

            // Update cc1 and cc2 with negative signs, using precomputed strides
            float *ptr_cc1 = cc1, *ptr_cc2 = cc2;
            *ptr_cc1++ = a11;
            *ptr_cc1++ = -a21;
            *ptr_cc1++ = a12;
            *ptr_cc1++ = -a22;
            *ptr_cc2++ = a31;
            *ptr_cc2++ = -a41;
            *ptr_cc2++ = a32;
            *ptr_cc2++ = -a42;

            aa1 += 4;
            aa2 += 4;
            bb1 += 4;
            bb2 += 4;
            cc1 += 4 * m;
            cc2 += 4 * m;
        }
        a11 = *(aa1 + 0);
        a12 = *(aa2 + 0);
        a22 = *(aa2 + 1);
        a32 = *(aa2 + 2);
        *(bb1 + 0) = a11;
        *(bb1 + 1) = 0.;
        *(bb1 + 2) = a12;
        *(bb1 + 3) = -a22;
        *(bb2 + 0) = a12;
        *(bb2 + 1) = a22;
        *(bb2 + 2) = a32;
        *(bb2 + 3) = 0.;
    }
    if (m - js == 1) {
        for (is = 0; is < js; is += 2) {
            float *ptr_a1 = aa1;
            a11 = *ptr_a1++;
            a21 = *ptr_a1++;
            a31 = *ptr_a1++;
            a41 = *ptr_a1;

            float *ptr_bb1 = bb1;
            *ptr_bb1++ = a11;
            *ptr_bb1++ = a21;
            *ptr_bb1++ = a31;
            *ptr_bb1++ = a41;

            float *ptr_cc1 = cc1, *ptr_cc2 = cc2;
            *ptr_cc1++ = a11;
            *ptr_cc1++ = -a21;
            *ptr_cc2++ = a31;
            *ptr_cc2++ = -a41;

            aa1 += 4;
            bb1 += 4;
            cc1 += 4 * m;
            cc2 += 4 * m;
        }
        a11 = *(aa1 + 0);
        *(bb1 + 0) = a11;
        *(bb1 + 1) = 0.;
    }
}
}
