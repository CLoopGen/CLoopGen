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
    aa1 = a + 0 * lda;
    a += lda;
    bb1 = b1 + 0 * m;
    b1 += 2 * m;
    cc1 = b2 + 0 * m;
    b2 += 2;
    for (is = 0; is < js; is++) {
        a11 = *(aa1 + 0);
        a21 = *(aa1 + 1);
        aa1 += 2;
        *(bb1 + 0) = a11;
        *(bb1 + 1) = -a21;
        *(cc1 + 0) = a11;
        *(cc1 + 1) = a21;
        bb1 += 2;
        cc1 += 2 * m;
    }
    if (js < m) {
        a11 = *(aa1 + 0);
        *(bb1 + 0) = a11;
        *(bb1 + 1) = 0.;
    }
}
}
