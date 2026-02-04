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
for (js = 0; js < m; js++) {
    aa1 = a + (js % 2) * lda;
    bb1 = b1 + (js % 4) * m;
    cc1 = b2 + (js % 4) * m;

    if (js + 1 < m) {
        a11 = *(aa1 + 0);
        a21 = *(aa1 + 1);
        a31 = *(aa1 + 2);
        a41 = *(aa1 + 3);

        *(bb1 + 0) = a11;
        *(bb1 + 1) = (js & 1) ? -a21 : 0.0f;
        *(bb1 + 2) = a31;
        *(bb1 + 3) = -a41;

        *(cc1 + 0) = a11;
        *(cc1 + 1) = a21;
        *(cc1 + 2) = a31;
        *(cc1 + 3) = a41;

        if (js < m - 2) {
            a12 = *(aa1 + 4);
            a22 = *(aa1 + 5);
            *(bb1 + 4) = a12;
            *(bb1 + 5) = -a22;
            *(cc1 + 4) = a12;
            *(cc1 + 5) = a22;
        }

        if (js < m - 3) {
            a32 = *(aa1 + 6);
            a42 = *(aa1 + 7);
            *(bb1 + 6) = a32;
            *(bb1 + 7) = -a42;
            *(cc1 + 6) = a32;
            *(cc1 + 7) = a42;
        }
    } else {
        a11 = *(aa1 + 0);
        *(bb1 + 0) = a11;
        *(bb1 + 1) = 0.0f;
    }
}
}
