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
    aa1 = a;
    aa2 = a + lda;
    a += 2 * lda + 2;
    bb1 = b1;
    bb2 = b1 + m;
    b1 += 2 * m + 2;
    cc1 = b2;
    cc2 = b2 + m;
    b2 += 2 * m + 2;

    if (js + 1 < m) {
        a11 = *aa1;
        a21 = aa1[1];
        a22 = aa2[1];
        *bb1 = a11;
        bb1[1] = a21;
        *bb2 = a21;
        bb2[1] = a22;
        aa1 += 2;
        aa2 += 2;
        bb1 += 2;
        bb2 += 2;
        cc1 += 2 * m;
        cc2 += 2 * m;

        for (is = 0; is < (m - js - 2); is += 2) {
            a11 = *aa1;
            a21 = aa1[1];
            a12 = *aa2;
            a22 = aa2[1];
            aa1 += 2;
            aa2 += 2;
            *bb1 = a11;
            bb1[1] = a21;
            *bb2 = a12;
            bb2[1] = a22;
            *cc1 = a11;
            cc1[1] = a12;
            *cc2 = a21;
            cc2[1] = a22;
            bb1 += 2;
            bb2 += 2;
            cc1 += 2 * m;
            cc2 += 2 * m;
        }

        if (is == (m - js - 2)) {
            a11 = *aa1;
            a12 = *aa2;
            *bb1 = a11;
            *bb2 = a12;
            *cc1 = a11;
            cc1[1] = a12;
        }
    } else if (js < m) {
        a11 = *aa1;
        *bb1 = a11;
    }
}
}
