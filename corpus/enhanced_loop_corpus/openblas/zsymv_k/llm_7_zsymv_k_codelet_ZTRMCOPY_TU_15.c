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
        float prev_bb1_0 = 0.0f; // Introduce scalar reduction-like variable
        for (is = 0; is < js; is += 2) {
            a11 = *(aa1 + 0);
            a21 = *(aa1 + 1);
            a31 = *(aa1 + 2);
            a41 = *(aa1 + 3);
            a12 = *(aa2 + 0);
            a22 = *(aa2 + 1);
            a32 = *(aa2 + 2);
            a42 = *(aa2 + 3);
            aa1 += 4;
            aa2 += 4;

            // Eliminate some data reuse, break WAW by writing through volatile intermediates
            volatile float v1 = a11, v2 = a21, v3 = a31, v4 = a41;
            volatile float w1 = a12, w2 = a22, w3 = a32, w4 = a42;

            *(bb1 + 0) = v1 + prev_bb1_0; // Introduce loop-carried RAW: depends on last iteration
            *(bb1 + 1) = v2;
            *(bb1 + 2) = v3;
            *(bb1 + 3) = v4;
            *(bb2 + 0) = w1;
            *(bb2 + 1) = w2;
            *(bb2 + 2) = w3;
            *(bb2 + 3) = w4;
            *(cc1 + 0) = v1;
            *(cc1 + 1) = v2;
            *(cc1 + 2) = w1;
            *(cc1 + 3) = w2;
            *(cc2 + 0) = v3;
            *(cc2 + 1) = v4;
            *(cc2 + 2) = w3;
            *(cc2 + 3) = w4;

            prev_bb1_0 = *(bb1 + 0); // Carry forward value — creates strong loop-carried dependency
            bb1 += 4;
            bb2 += 4;
            cc1 += 4 * m;
            cc2 += 4 * m;
        }
        a11 = *(aa1 + 0);
        a21 = *(aa1 + 1);
        a12 = *(aa2 + 0);
        a22 = *(aa2 + 1);
        a32 = *(aa2 + 2);
        a42 = *(aa2 + 3);
        *(bb1 + 0) = a11 + prev_bb1_0;
        *(bb1 + 1) = a21;
        *(bb1 + 2) = a12;
        *(bb1 + 3) = a22;
        *(bb2 + 0) = a12;
        *(bb2 + 1) = a22;
        *(bb2 + 2) = a32;
        *(bb2 + 3) = a42;
    }
    if (m - js == 1) {
        float prev_bb1_scalar = 0.0f;
        for (is = 0; is < js; is += 2) {
            a11 = *(aa1 + 0);
            a21 = *(aa1 + 1);
            a31 = *(aa1 + 2);
            a41 = *(aa1 + 3);
            aa1 += 4;

            volatile float x1 = a11, x2 = a21, x3 = a31, x4 = a41;

            *(bb1 + 0) = x1 + prev_bb1_scalar;
            *(bb1 + 1) = x2;
            *(bb1 + 2) = x3;
            *(bb1 + 3) = x4;
            *(cc1 + 0) = x1;
            *(cc1 + 1) = x2;
            *(cc2 + 0) = x3;
            *(cc2 + 1) = x4;

            prev_bb1_scalar = *(bb1 + 0);
            bb1 += 4;
            cc1 += 4 * m;
            cc2 += 4 * m;
        }
        a11 = *(aa1 + 0);
        a21 = *(aa1 + 1);
        *(bb1 + 0) = a11 + prev_bb1_scalar;
        *(bb1 + 1) = a21;
    }
}
}
