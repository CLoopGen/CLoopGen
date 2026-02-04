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
    bb1 = b1 + js * m;
    cc1 = b2 + js * m;
    for (is = 0; is < js; is++) {
        float temp = *(aa1 + is);
        *(bb1 + is) = temp;
        *(cc1 + is) = temp;
    }
    if (js < m) {
        *(bb1 + js) = *(aa1 + js);
        if (js + 1 < m) {
            *(bb1 + js + 1) = *(aa1 + js + 1);
        }
    }
}
}
