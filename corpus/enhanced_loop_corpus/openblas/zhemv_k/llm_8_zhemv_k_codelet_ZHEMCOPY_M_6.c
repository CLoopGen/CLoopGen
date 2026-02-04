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
        b1 += 16 * m + 8;
        cc1 = b2 + 0 * m;
        cc2 = b2 + 4 * m;
        float *cc3 = b2 + 8 * m;
        float *cc4 = b2 + 12 * m;
        b2 += 16 * m + 8;

        for (is = 0; is < ((m - js - 4) >> 2) + 1; is++) {
            a11 = *(aa1 + 0); a21 = *(aa1 + 1); a31 = *(aa1 + 2); a41 = *(aa1 + 3);
            a12 = *(aa2 + 0); a22 = *(aa2 + 1); 
            float a32 = *(aa2 + 2), a42 = *(aa2 + 3);
            float a13 = *(aa3 + 0), a23 = *(aa3 + 1), a33 = *(aa3 + 2), a43 = *(aa3 + 3);
            float a14 = *(aa4 + 0), a24 = *(aa4 + 1), a34 = *(aa4 + 2), a44 = *(aa4 + 3);

            *(bb1 + 0) = a11; *(bb1 + 1) = -a21; *(bb1 + 2) = a31; *(bb1 + 3) = -a41;
            *(bb2 + 0) = a12; *(bb2 + 1) = -a22; *(bb2 + 2) = a32; *(bb2 + 3) = -a42;
            *(bb3 + 0) = a13; *(bb3 + 1) = -a23; *(bb3 + 2) = a33; *(bb3 + 3) = -a43;
            *(bb4 + 0) = a14; *(bb4 + 1) = -a24; *(bb4 + 2) = a34; *(bb4 + 3) = -a44;

            *(cc1 + 0) = a11; *(cc1 + 1) = a21; *(cc1 + 2) = a12; *(cc1 + 3) = a22;
            *(cc2 + 0) = a31; *(cc2 + 1) = a41; *(cc2 + 2) = a32; *(cc2 + 3) = a42;
            *(cc3 + 0) = a13; *(cc3 + 1) = a23; *(cc3 + 2) = a14; *(cc3 + 3) = a24;
            *(cc4 + 0) = a33; *(cc4 + 1) = a43; *(cc4 + 2) = a34; *(cc4 + 3) = a44;

            aa1 += 8; aa2 += 8; aa3 += 8; aa4 += 8;
            bb1 += 8; bb2 += 8; bb3 += 8; bb4 += 8;
            cc1 += 8 * m; cc2 += 8 * m; cc3 += 8 * m; cc4 += 8 * m;
        }
    }
}
}
