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
for (js = 0; js < m; js += 4) {
    aa1 = a + 0 * lda;
    aa2 = a + 1 * lda;
    a += 4 * lda;
    bb1 = b1 + 0 * m;
    bb2 = b1 + 4 * m;
    b1 += 8 * m;
    cc1 = b2 + 0 * m;
    cc2 = b2 + 4 * m;
    b2 += 8;
    if (m - js >= 4) {
        for (is = 0; is < js; is += 4) {
            for (BLASLONG k = 0; k < 4; ++k) {
                a11 = *(aa1 + k);
                a21 = *(aa1 + k + 4);
                a31 = *(aa1 + k + 8);
                a41 = *(aa1 + k + 12);
                a12 = *(aa2 + k);
                a22 = *(aa2 + k + 4);
                a32 = *(aa2 + k + 8);
                a42 = *(aa2 + k + 12);

                *(bb1 + k)         = a11;
                *(bb1 + k + 4)     = a21;
                *(bb1 + k + 8)     = a31;
                *(bb1 + k + 12)    = a41;
                *(bb2 + k)         = a12;
                *(bb2 + k + 4)     = a22;
                *(bb2 + k + 8)     = a32;
                *(bb2 + k + 12)    = a42;

                *(cc1 + k * m)     = a11;
                *(cc1 + k * m + 1) = a21;
                *(cc1 + k * m + 2) = a12;
                *(cc1 + k * m + 3) = a22;
                *(cc2 + k * m)     = a31;
                *(cc2 + k * m + 1) = a41;
                *(cc2 + k * m + 2) = a32;
                *(cc2 + k * m + 3) = a42;
            }
            aa1 += 16;
            aa2 += 16;
            bb1 += 16;
            bb2 += 16;
            cc1 += 16;
            cc2 += 16;
        }
        a11 = *(aa1 + 0); a21 = *(aa1 + 1); a31 = *(aa1 + 2); a41 = *(aa1 + 3);
        a12 = *(aa2 + 0); a22 = *(aa2 + 1); a32 = *(aa2 + 2); a42 = *(aa2 + 3);
        *(bb1 + 0) = a11; *(bb1 + 1) = a21; *(bb1 + 2) = a31; *(bb1 + 3) = a41;
        *(bb2 + 0) = a12; *(bb2 + 1) = a22; *(bb2 + 2) = a32; *(bb2 + 3) = a42;
        *(cc1 + 0) = a11; *(cc1 + 1) = a21; *(cc1 + 2) = a12; *(cc1 + 3) = a22;
        *(cc2 + 0) = a31; *(cc2 + 1) = a41; *(cc2 + 2) = a32; *(cc2 + 3) = a42;
        bb1 += 4; bb2 += 4; cc1 += 4 * m; cc2 += 4 * m;

        a11 = *(aa1 + 4); a21 = *(aa1 + 5); a12 = *(aa2 + 4); a22 = *(aa2 + 5);
        *(bb1 + 0) = a11; *(bb1 + 1) = a21; *(bb1 + 2) = a12; *(bb1 + 3) = a22;
        *(bb2 + 0) = a12; *(bb2 + 1) = a22; *(bb2 + 2) = *(aa2 + 6); *(bb2 + 3) = *(aa2 + 7);
        bb1 += 4; bb2 += 4; cc1 += 4 * m; cc2 += 4 * m;

        a11 = *(aa1 + 8); a21 = *(aa1 + 9); a12 = *(aa2 + 8); a22 = *(aa2 + 9);
        *(bb1 + 0) = a11; *(bb1 + 1) = a21; *(bb1 + 2) = a12; *(bb1 + 3) = a22;
        *(bb2 + 0) = a12; *(bb2 + 1) = a22; *(bb2 + 2) = *(aa2 + 10); *(bb2 + 3) = *(aa2 + 11);
        bb1 += 4; bb2 += 4; cc1 += 4 * m; cc2 += 4 * m;

        a11 = *(aa1 + 12); a21 = *(aa1 + 13); a12 = *(aa2 + 12); a22 = *(aa2 + 13);
        *(bb1 + 0) = a11; *(bb1 + 1) = a21; *(bb1 + 2) = a12; *(bb1 + 3) = a22;
        *(bb2 + 0) = a12; *(bb2 + 1) = a22; *(bb2 + 2) = *(aa2 + 14); *(bb2 + 3) = *(aa2 + 15);
    }
}
}
