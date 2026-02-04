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
    if (m - js >= 4) {
        aa1 = a + 0 * lda;
        aa2 = a + 1 * lda;
        float *aa3 = a + 2 * lda;
        float *aa4 = a + 3 * lda;
        a += 4 * lda + 8;

        bb1 = b1 + 0 * m;
        bb2 = b1 + 4 * m;
        float *bb3 = b1 + 8 * m;
        float *bb4 = b1 + 12 * m;
        b1 += 8 * m + 8;

        cc1 = b2 + 0 * m;
        cc2 = b2 + 4 * m;
        float *cc3 = b2 + 8 * m;
        float *cc4 = b2 + 12 * m;
        b2 += 8 * m + 8;

        for (is = 0; is < ((m - js - 4) >> 2) + 1; is++) {
            if (is == 0) {
                a11 = *(aa1 + 0); a21 = *(aa1 + 1); a31 = *(aa1 + 2); a41 = *(aa1 + 3);
                a12 = *(aa2 + 0); a22 = *(aa2 + 1); a32 = *(aa2 + 2); a42 = *(aa2 + 3);

                *(bb1 + 0) = a11; *(bb1 + 1) = a21; *(bb1 + 2) = a31; *(bb1 + 3) = a41;
                *(bb2 + 0) = a12; *(bb2 + 1) = a22; *(bb2 + 2) = a32; *(bb2 + 3) = a42;

                *(cc1 + 0) = a11; *(cc1 + 1) = a21; *(cc1 + 2) = a12; *(cc1 + 3) = a22;
                *(cc2 + 0) = a31; *(cc2 + 1) = a41; *(cc2 + 2) = a32; *(cc2 + 3) = a42;

                aa1 += 4; aa2 += 4;
                bb1 += 4; bb2 += 4;
                cc1 += 4 * m; cc2 += 4 * m;
            }

            a11 = *(aa1 + 0); a21 = *(aa1 + 1); a31 = *(aa1 + 2); a41 = *(aa1 + 3);
            a12 = *(aa2 + 0); a22 = *(aa2 + 1); a32 = *(aa2 + 2); a42 = *(aa2 + 3);

            float a51 = *(aa3 + 0), a61 = *(aa3 + 1), a71 = *(aa3 + 2), a81 = *(aa3 + 3);
            float a52 = *(aa4 + 0), a62 = *(aa4 + 1), a72 = *(aa4 + 2), a82 = *(aa4 + 3);

            *(bb1 + 0) = a11; *(bb1 + 1) = a21; *(bb1 + 2) = a31; *(bb1 + 3) = a41;
            *(bb2 + 0) = a12; *(bb2 + 1) = a22; *(bb2 + 2) = a32; *(bb2 + 3) = a42;
            *(bb3 + 0) = a51; *(bb3 + 1) = a61; *(bb3 + 2) = a71; *(bb3 + 3) = a81;
            *(bb4 + 0) = a52; *(bb4 + 1) = a62; *(bb4 + 2) = a72; *(bb4 + 3) = a82;

            *(cc1 + 0) = a11; *(cc1 + 1) = a21; *(cc1 + 2) = a12; *(cc1 + 3) = a22;
            *(cc2 + 0) = a31; *(cc2 + 1) = a41; *(cc2 + 2) = a32; *(cc2 + 3) = a42;
            *(cc3 + 0) = a51; *(cc3 + 1) = a61; *(cc3 + 2) = a52; *(cc3 + 3) = a62;
            *(cc4 + 0) = a71; *(cc4 + 1) = a81; *(cc4 + 2) = a72; *(cc4 + 3) = a82;

            aa1 += 4; aa2 += 4; aa3 += 4; aa4 += 4;
            bb1 += 4; bb2 += 4; bb3 += 4; bb4 += 4;
            cc1 += 4 * m; cc2 += 4 * m; cc3 += 4 * m; cc4 += 4 * m;
        }
    }
}
}
