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
    BLASLONG offset_a = 0;
    BLASLONG offset_b1 = 0;
    BLASLONG offset_b2 = 0;
    aa1 = a;
    aa2 = a + lda;
    bb1 = b1;
    bb2 = b1 + m;
    cc1 = b2;
    cc2 = b2 + m;
    if (m - js >= 2) {
        for (is = 0; is < js; is += 2) {
            a11 = aa1[offset_a];
            a21 = aa1[offset_a + 1];
            a12 = aa2[offset_a];
            a22 = aa2[offset_a + 1];
            bb1[offset_b1] = a11;
            bb1[offset_b1 + 1] = a21;
            bb2[offset_b1] = a12;
            bb2[offset_b1 + 1] = a22;
            cc1[offset_b2] = a11;
            cc1[offset_b2 + 1] = a12;
            cc2[offset_b2] = a21;
            cc2[offset_b2 + 1] = a22;
            offset_a += 2;
            offset_b1 += 2;
            offset_b2 += 2 * m;
        }
        a11 = aa1[offset_a];
        a12 = aa2[offset_a];
        a22 = aa2[offset_a + 1];
        bb1[offset_b1] = a11;
        bb1[offset_b1 + 1] = a12;
        bb2[offset_b1] = a12;
        bb2[offset_b1 + 1] = a22;
    }
    if (m - js == 1) {
        for (is = 0; is < js; is += 2) {
            a11 = aa1[offset_a];
            a21 = aa1[offset_a + 1];
            bb1[offset_b1] = a11;
            bb1[offset_b1 + 1] = a21;
            cc1[offset_b2] = a11;
            cc2[offset_b2] = a21;
            offset_a += 2;
            offset_b1 += 2;
            offset_b2 += 2 * m;
        }
        a11 = aa1[offset_a];
        bb1[offset_b1] = a11;
    }
    a += 2 * lda;
    b1 += 2 * m;
    b2 += 2;
}
}
