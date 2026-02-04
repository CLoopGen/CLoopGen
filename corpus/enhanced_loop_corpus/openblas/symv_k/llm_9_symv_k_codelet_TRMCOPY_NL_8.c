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
    a += lda + 1;
    bb1 = b1 + js * m;
    bb2 = b1 + (js + 1) * m;
    cc1 = b2 + js * m;
    cc2 = b2 + (js + 1) * m;

    if (js + 1 < m) {
        a11 = *(aa1 + 0);
        a12 = *(aa2 + 0);
        *(bb1 + js) = a11;
        *(bb2 + js) = a12;
        *(cc1 + js + 1) = a12;
        *(cc2 + js + 1) = *(aa2 + 1);

        for (is = js + 1; is < m && is < js + 4; is++) {
            a11 = *(aa1 + (is - js));
            a21 = *(aa1 + (is - js) + 1);
            a12 = *(aa2 + (is - js));
            a22 = *(aa2 + (is - js) + 1);

            *(bb1 + is) = a11;
            *(bb1 + is + 1) = a21;
            *(bb2 + is) = a12;
            *(bb2 + is + 1) = a22;

            *(cc1 + is) = a11;
            *(cc1 + is + 1) = a12;
            *(cc2 + is) = a21;
            *(cc2 + is + 1) = a22;
        }
    } else {
        a11 = *(aa1 + 0);
        *(bb1 + js) = a11;
    }
}
}
