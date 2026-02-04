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
        a += 4 * lda;
        bb1 = b1 + 0 * m;
        bb2 = b1 + 4 * m;
        b1 += 8 * m;
        cc1 = b2 + 0 * m;
        cc2 = b2 + 4 * m;
        b2 += 8;

        for (is = 0; is < js; is += 4) {
            a11 = *(aa1 + 0); a21 = *(aa1 + 1); a31 = *(aa1 + 2); a41 = *(aa1 + 3);
            a12 = *(aa2 + 0); a22 = *(aa2 + 1); a32 = *(aa2 + 2); a42 = *(aa2 + 3);
            float a13 = *(aa3 + 0), a23 = *(aa3 + 1), a33 = *(aa3 + 2), a43 = *(aa3 + 3);
            float a14 = *(aa4 + 0), a24 = *(aa4 + 1), a34 = *(aa4 + 2), a44 = *(aa4 + 3);

            aa1 += 4; aa2 += 4; aa3 += 4; aa4 += 4;

            *(bb1 + 0) = a11; *(bb1 + 1) = a21; *(bb1 + 2) = a31; *(bb1 + 3) = a41;
            *(bb1 + 4) = a12; *(bb1 + 5) = a22; *(bb1 + 6) = a32; *(bb1 + 7) = a42;
            *(bb1 + 8) = a13; *(bb1 + 9) = a23; *(bb1 +10) = a33; *(bb1 +11) = a43;
            *(bb1 +12) = a14; *(bb1 +13) = a24; *(bb1 +14) = a34; *(bb1 +15) = a44;

            *(bb2 + 0) = a11; *(bb2 + 1) = a12; *(bb2 + 2) = a13; *(bb2 + 3) = a14;
            *(bb2 + 4) = a21; *(bb2 + 5) = a22; *(bb2 + 6) = a23; *(bb2 + 7) = a24;
            *(bb2 + 8) = a31; *(bb2 + 9) = a32; *(bb2+10) = a33; *(bb2+11) = a34;
            *(bb2+12) = a41; *(bb2+13) = a42; *(bb2+14) = a43; *(bb2+15) = a44;

            *(cc1 + 0) = a11; *(cc1 + 1) = a21; *(cc1 + m) = a12; *(cc1 + m+1) = a22;
            *(cc1 + 2*m) = a13; *(cc1 + 2*m+1) = a23; *(cc1 + 3*m) = a14; *(cc1 + 3*m+1) = a24;
            *(cc2 + 0) = a31; *(cc2 + 1) = a41; *(cc2 + m) = a32; *(cc2 + m+1) = a42;
            *(cc2 + 2*m) = a33; *(cc2 + 2*m+1) = a43; *(cc2 + 3*m) = a34; *(cc2 + 3*m+1) = a44;

            bb1 += 16;
            bb2 += 16;
            cc1 += 4 * m;
            cc2 += 4 * m;
        }

        a11 = *(aa1 + 0); a21 = *(aa1 + 1); a12 = *(aa2 + 0); a22 = *(aa2 + 1);
        a31 = *(aa3 + 0); a41 = *(aa3 + 1); a32 = *(aa4 + 0); a42 = *(aa4 + 1);

        *(bb1 + 0) = a11; *(bb1 + 1) = a21; *(bb1 + 2) = a12; *(bb1 + 3) = a22;
        *(bb1 + 4) = a31; *(bb1 + 5) = a41; *(bb1 + 6) = a32; *(bb1 + 7) = a42;

        *(bb2 + 0) = a11; *(bb2 + 1) = a12; *(bb2 + 2) = a31; *(bb2 + 3) = a32;
        *(bb2 + 4) = a21; *(bb2 + 5) = a22; *(bb2 + 6) = a41; *(bb2 + 7) = a42;
    }
}
}
