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
        a11 = aa1[0];
        a21 = aa1[1];
        a12 = aa2[0];
        a22 = aa2[1];

        bb1[0] = a11;
        bb1[1] = a21;
        bb2[0] = a12;
        bb2[1] = a22;

        cc1[0] = a11;
        cc1[1] = a12;
        cc2[0] = a21;
        cc2[1] = a22;

        for (BLASLONG is = 2; is < m; is += 2) {
            float *a_next1 = aa1 + is;
            float *a_next2 = aa2 + is;
            float *b_next1 = bb1 + is;
            float *b_next2 = bb2 + is;
            float *c_next1 = cc1 + is * m;
            float *c_next2 = cc2 + is * m;

            a11 = a_next1[0];
            a21 = a_next1[1];
            a12 = a_next2[0];
            a22 = a_next2[1];

            b_next1[0] = a11;
            b_next1[1] = a21;
            b_next2[0] = a12;
            b_next2[1] = a22;

            c_next1[0] = a11;
            c_next1[1] = a12;
            c_next2[0] = a21;
            c_next2[1] = a22;
        }

        if (m % 2 == 1) {
            BLASLONG is = m - 1;
            a11 = *(aa1 + is);
            a12 = *(aa2 + is);
            *(bb1 + is) = a11;
            *(bb2 + is) = a12;
            *(cc1 + is) = a11;
            *(cc1 + m) = a12;
        }
    } else {
        a11 = *(aa1 + 0);
        *(bb1 + 0) = a11;
    }
}
}
