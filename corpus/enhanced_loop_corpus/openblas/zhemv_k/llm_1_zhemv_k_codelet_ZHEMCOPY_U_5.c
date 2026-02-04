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
for (js = 0; js < m; js += 2) {
    aa1 = a + 0 * lda;
    aa2 = a + 1 * lda;
    a += 2 * lda;
    bb1 = b1 + 0 * m;
    bb2 = b1 + 2 * m;
    b1 += 4 * m;
    cc1 = b2 + 0 * m;
    cc2 = b2 + 2 * m;
    b2 += 4;
    if (m - js >= 2) {
        for (is = 0; is < js; is += 2) {
            for (BLASLONG k = 0; k < 4; ++k) {
                float temp_aa1 = *(aa1 + k);
                float temp_aa2 = *(aa2 + k);
                *(bb1 + k) = temp_aa1;
                *(bb2 + k) = temp_aa2;
                *(cc1 + k) = (k % 2 == 0) ? temp_aa1 : -temp_aa1;
                *(cc2 + k) = (k % 2 == 0) ? temp_aa2 : -temp_aa2;
            }
            aa1 += 4;
            aa2 += 4;
            bb1 += 4;
            bb2 += 4;
            cc1 += 4 * m;
            cc2 += 4 * m;
        }
        a11 = *(aa1 + 0);
        a12 = *(aa2 + 0);
        a22 = *(aa2 + 1);
        a32 = *(aa2 + 2);
        *(bb1 + 0) = a11;
        *(bb1 + 1) = 0.;
        *(bb1 + 2) = a12;
        *(bb1 + 3) = -a22;
        *(bb2 + 0) = a12;
        *(bb2 + 1) = a22;
        *(bb2 + 2) = a32;
        *(bb2 + 3) = 0.;
    }
    if (m - js == 1) {
        for (is = 0; is < js; is += 2) {
            for (BLASLONG k = 0; k < 4; ++k) {
                float temp_aa1 = *(aa1 + k);
                *(bb1 + k) = temp_aa1;
                *(cc1 + k) = (k % 2 == 0) ? temp_aa1 : -temp_aa1;
            }
            aa1 += 4;
            bb1 += 4;
            cc1 += 4 * m;
            cc2 += 4 * m;
        }
        a11 = *(aa1 + 0);
        *(bb1 + 0) = a11;
        *(bb1 + 1) = 0.;
    }
}
}
