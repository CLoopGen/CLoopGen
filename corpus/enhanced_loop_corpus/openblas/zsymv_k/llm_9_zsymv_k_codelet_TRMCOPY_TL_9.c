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
    bb1 = b1 + 0 * m;
    bb2 = b1 + 1 * m;
    cc1 = b2 + 0 * m;
    cc2 = b2 + 1 * m;

    if (js % 2 == 0 && js + 1 < m) {
        a11 = *(aa1 + 0);
        a21 = *(aa1 + 1);
        a22 = *(aa2 + 1);
        *(bb1 + 0) = a11;
        *(bb1 + 1) = a21;
        *(bb2 + 0) = a21;
        *(bb2 + 1) = a22;

        for (BLASLONG is = 1; is < m - js - 1; is++) {
            float *t_aa1 = aa1 + 2 * is;
            float *t_aa2 = aa2 + 2 * is;
            float *t_bb1 = bb1 + 2 * is;
            float *t_bb2 = bb2 + 2 * is;
            float *t_cc1 = cc1 + 2 * is * m;
            float *t_cc2 = cc2 + 2 * is * m;

            a11 = *(t_aa1 + 0);
            a21 = *(t_aa1 + 1);
            a12 = *(t_aa2 + 0);
            a22 = *(t_aa2 + 1);

            *(t_bb1 + 0) = a11;
            *(t_bb1 + 1) = a21;
            *(t_bb2 + 0) = a12;
            *(t_bb2 + 1) = a22;
            *(t_cc1 + 0) = a11;
            *(t_cc1 + 1) = a12;
            *(t_cc2 + 0) = a21;
            *(t_cc2 + 1) = a22;
        }

        BLASLONG rem = (m - js - 1) % 2 == 1 ? 1 : 0;
        if (rem) {
            BLASLONG offset = 2 * ((m - js - 2) / 2);
            a11 = *(aa1 + offset + 0);
            a12 = *(aa2 + offset + 0);
            *(bb1 + offset + 0) = a11;
            *(bb2 + offset + 0) = a12;
            *(cc1 + offset + 0) = a11;
            *(cc1 + offset + 1) = a12;
        }

        a += 2 * lda + 2;
        b1 += 2 * m + 2;
        b2 += 2 * m + 2;
        js++; 
    } else {
        a11 = *(aa1 + 0);
        *(bb1 + 0) = a11;
        a += lda + 1;
        b1 += m + 1;
        b2 += m + 1;
    }
}
}
