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
    aa1 = a + (js % 2) * lda;
    aa2 = a + ((js + 1) % 2) * lda;
    bb1 = b1 + (js % 2) * m;
    bb2 = b1 + ((js + 1) % 2) * m;
    cc1 = b2 + (js % 2) * m;
    cc2 = b2 + ((js + 1) % 2) * m;

    if (js + 1 < m) {
        a11 = *(aa1 + js);
        a21 = *(aa1 + js + 1);
        a12 = *(aa2 + js);
        a22 = *(aa2 + js + 1);

        *(bb1 + js) = a11;
        *(bb1 + js + 1) = a21;
        *(bb2 + js) = a12;
        *(bb2 + js + 1) = a22;

        *(cc1 + js) = a11;
        *(cc1 + js + 1) = a12;
        *(cc2 + js) = a21;
        *(cc2 + js + 1) = a22;
    }
    else if (js < m) {
        a11 = *(aa1 + js);
        *(bb1 + js) = a11;
    }

    if (js % 2 == 1) {
        a += 2 * lda + 2;
        b1 += 2 * m + 2;
        b2 += 2 * m + 2;
    }
}
}
