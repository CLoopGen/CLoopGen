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
for (js = 0; js < m; js += 2) {
    aa1 = a + 0 * lda;
    aa2 = a + 1 * lda;
    a += 2 * lda;
    bb1 = b1 + 0 * m;
    bb2 = b1 + 1 * m;
    b1 += 2 * m;
    cc1 = b2 + 0 * m;
    cc2 = b2 + 1 * m;
    b2 += 2;
    if (m - js >= 2) {
        for (is = 0; is < js; is += 2) {
            a11 = aa1[is];
            a21 = aa1[is + 1];
            a12 = aa2[is];
            a22 = aa2[is + 1];
            bb1[is] = a11;
            bb1[is + 1] = a21;
            bb2[is] = a12;
            bb2[is + 1] = a22;
            cc1[is * m] = a11;
            cc1[(is + 1) * m] = a12;
            cc2[is * m] = a21;
            cc2[(is + 1) * m] = a22;
        }
        a11 = aa1[js];
        a12 = aa2[js];
        a22 = aa2[js + 1];
        bb1[js] = a11;
        bb1[js + 1] = a12;
        bb2[js] = a12;
        bb2[js + 1] = a22;
    }
    if (m - js == 1) {
        for (is = 0; is < js; is += 2) {
            a11 = aa1[is];
            a21 = aa1[is + 1];
            bb1[is] = a11;
            bb1[is + 1] = a21;
            cc1[is * m] = a11;
            cc2[is * m] = a21;
        }
        a11 = aa1[js];
        bb1[js] = a11;
    }
}
}
