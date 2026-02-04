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
for (js = 0; js < m; js++) {
    aa1 = a + 0 * lda;
    a += lda + 1;
    bb1 = b1 + 0 * m;
    b1 += m + 1;
    cc1 = b2 + 0 * m;
    b2 += m + 1;

    if (js % 2 == 0 && js + 1 < m) {
        a11 = *(aa1 + 0);
        a21 = *(aa1 + 1);
        *(bb1 + 0) = a11;
        *(bb1 + 1) = a21;
        *(cc1 + 0) = a11;
        *(cc1 + m) = a21;

        if (js + 2 < m) {
            a12 = *(aa1 + 2);
            *(bb1 + 2) = a12;
            *(cc1 + 1) = a12;
        }

        if (js + 3 < m) {
            a22 = *(aa1 + 3);
            *(bb1 + 3) = a22;
            *(cc1 + m + 1) = a22;
        }
    } else if (js % 2 == 1) {
        a11 = *(aa1 + 0);
        *(bb1 + 0) = a11;
    }
}
}
