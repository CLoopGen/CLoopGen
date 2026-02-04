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
    BLASLONG offset_a = 0;
    BLASLONG offset_b1 = 0;
    BLASLONG offset_b2 = 0;
    aa1 = a;
    aa2 = a + lda;
    bb1 = b1;
    bb2 = b1 + 2 * m;
    cc1 = b2;
    cc2 = b2 + 2 * m;
    if (m - js >= 2) {
        for (is = 0; is < js; is += 2) {
            a11 = *(aa1 + offset_a + 0);
            a21 = *(aa1 + offset_a + 1);
            a31 = *(aa1 + offset_a + 2);
            a41 = *(aa1 + offset_a + 3);
            a12 = *(aa2 + offset_a + 0);
            a22 = *(aa2 + offset_a + 1);
            a32 = *(aa2 + offset_a + 2);
            a42 = *(aa2 + offset_a + 3);
            offset_a += 4;
            *(bb1 + offset_b1 + 0) = a11;
            *(bb1 + offset_b1 + 1) = a21;
            *(bb1 + offset_b1 + 2) = a31;
            *(bb1 + offset_b1 + 3) = a41;
            *(bb2 + offset_b1 + 0) = a12;
            *(bb2 + offset_b1 + 1) = a22;
            *(bb2 + offset_b1 + 2) = a32;
            *(bb2 + offset_b1 + 3) = a42;
            *(cc1 + offset_b2 + 0*m) = a11;
            *(cc1 + offset_b2 + 1*m) = a21;
            *(cc1 + offset_b2 + 2*m) = a12;
            *(cc1 + offset_b2 + 3*m) = a22;
            *(cc2 + offset_b2 + 0*m) = a31;
            *(cc2 + offset_b2 + 1*m) = a41;
            *(cc2 + offset_b2 + 2*m) = a32;
            *(cc2 + offset_b2 + 3*m) = a42;
            offset_b1 += 4;
            offset_b2 += 4;
        }
        a11 = *(aa1 + offset_a + 0);
        a21 = *(aa1 + offset_a + 1);
        a12 = *(aa2 + offset_a + 0);
        a22 = *(aa2 + offset_a + 1);
        a32 = *(aa2 + offset_a + 2);
        a42 = *(aa2 + offset_a + 3);
        *(bb1 + offset_b1 + 0) = a11;
        *(bb1 + offset_b1 + 1) = a21;
        *(bb1 + offset_b1 + 2) = a12;
        *(bb1 + offset_b1 + 3) = a22;
        *(bb2 + offset_b1 + 0) = a12;
        *(bb2 + offset_b1 + 1) = a22;
        *(bb2 + offset_b1 + 2) = a32;
        *(bb2 + offset_b1 + 3) = a42;
    }
    if (m - js == 1) {
        for (is = 0; is < js; is += 2) {
            a11 = *(aa1 + offset_a + 0);
            a21 = *(aa1 + offset_a + 1);
            a31 = *(aa1 + offset_a + 2);
            a41 = *(aa1 + offset_a + 3);
            offset_a += 4;
            *(bb1 + offset_b1 + 0) = a11;
            *(bb1 + offset_b1 + 1) = a21;
            *(bb1 + offset_b1 + 2) = a31;
            *(bb1 + offset_b1 + 3) = a41;
            *(cc1 + offset_b2 + 0*m) = a11;
            *(cc1 + offset_b2 + 1*m) = a21;
            *(cc2 + offset_b2 + 0*m) = a31;
            *(cc2 + offset_b2 + 1*m) = a41;
            offset_b1 += 4;
            offset_b2 += 4;
        }
        a11 = *(aa1 + offset_a + 0);
        a21 = *(aa1 + offset_a + 1);
        *(bb1 + offset_b1 + 0) = a11;
        *(bb1 + offset_b1 + 1) = a21;
    }
    a += 2 * lda;
    b1 += 4 * m;
    b2 += 4;
}
}
