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
    BLASLONG offset_b = 0;
    BLASLONG offset_c = 0;
    aa1 = a;
    aa2 = a + lda;
    bb1 = b1;
    bb2 = b1 + m;
    cc1 = b2;
    cc2 = b2 + m;
    a += 2 * lda;
    b1 += 2 * m;
    b2 += 2;
    if (m - js >= 2) {
        for (is = 0; is < js; is += 2) {
            a11 = *(aa1 + offset_a);
            a21 = *(aa1 + offset_a + 1);
            a12 = *(aa2 + offset_a);
            a22 = *(aa2 + offset_a + 1);
            offset_a += 2;
            *(bb1 + offset_b) = a11;
            *(bb1 + offset_b + 1) = a21;
            *(bb2 + offset_b) = a12;
            *(bb2 + offset_b + 1) = a22;
            offset_b += 2;
            *(cc1 + offset_c) = a11;
            *(cc1 + offset_c + m) = a12;
            *(cc2 + offset_c) = a21;
            *(cc2 + offset_c + m) = a22;
            offset_c += 2 * m;
        }
        a11 = *(aa1 + js);
        a12 = *(aa2 + js);
        a22 = *(aa2 + js + 1);
        *(bb1 + js) = a11;
        *(bb1 + js + 1) = a12;
        *(bb2 + js) = a12;
        *(bb2 + js + 1) = a22;
    }
    if (m - js == 1) {
        for (is = 0; is < js; is += 2) {
            a11 = *(aa1 + is);
            a21 = *(aa1 + is + 1);
            *(bb1 + is) = a11;
            *(bb1 + is + 1) = a21;
            *(cc1 + is * m) = a11;
            *(cc2 + is * m) = a21;
        }
        *(bb1 + js) = *(aa1 + js);
    }
}
}
