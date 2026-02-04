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
    bb1 = b1 + js * m;
    cc1 = b2 + js * m;
    for (is = 0; is < js; is++) {
        a11 = *(aa1 + is);
        *(bb1 + is) = a11;
        *(cc1 + is * m + js) = a11;
    }
    if (js < m) {
        a11 = *(aa1 + js);
        *(bb1 + js) = a11;
        *(cc1 + js * m + js) = a11;
    }
    a += lda;
    b1 += m;
    b2 += 1;
}
}
