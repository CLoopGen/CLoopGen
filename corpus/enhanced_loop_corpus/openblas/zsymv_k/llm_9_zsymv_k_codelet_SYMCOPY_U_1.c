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
    aa2 = a + 1 * lda;
    b1 += lda;
    b2 += 1;
    bb1 = b1;
    cc1 = b2;
    for (is = 0; is < js; is++) {
        a11 = *(aa1 + 0);
        *(bb1 + 0) = a11;
        *(cc1 + 0) = a11;
        bb1++;
        cc1 += m;
        aa1++;
        if (lda > 1) aa2++;
    }
    if (js < m) {
        a11 = *(aa1 + 0);
        *(bb1 + 0) = a11;
    }
    a += lda;
}
}
