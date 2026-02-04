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
    a += 2 * lda + 4;
    bb1 = b1 + 0 * m;
    bb2 = b1 + 2 * m;
    b1 += 4 * m + 4;
    cc1 = b2 + 0 * m;
    cc2 = b2 + 2 * m;
    b2 += 4 * m + 4;

    if (m - js >= 2) {
        float temp_a11 = *(aa1 + 0);
        float temp_a21 = *(aa1 + 1);
        float temp_a31 = *(aa1 + 2);
        float temp_a41 = *(aa1 + 3);
        float temp_a12 = *(aa2 + 2);
        float temp_a22 = *(aa2 + 3);

        *(bb1 + 0) = temp_a11;
        *(bb1 + 1) = temp_a21;
        *(bb1 + 2) = temp_a31;
        *(bb1 + 3) = temp_a41;
        *(bb2 + 0) = temp_a31;
        *(bb2 + 1) = temp_a41;
        *(bb2 + 2) = temp_a12;
        *(bb2 + 3) = temp_a22;

        aa1 += 4;
        aa2 += 4;
        bb1 += 4;
        bb2 += 4;
        cc1 += 4 * m;
        cc2 += 4 * m;

        BLASLONG iter = (m - js - 2) / 2;
        for (BLASLONG i = 0; i < iter; i++) {
            float t11 = *(aa1 + 0), t21 = *(aa1 + 1), t31 = *(aa1 + 2), t41 = *(aa1 + 3);
            float t12 = *(aa2 + 0), t22 = *(aa2 + 1), t32 = *(aa2 + 2), t42 = *(aa2 + 3);

            *(bb1 + 0) = t11; *(bb1 + 1) = t21; *(bb1 + 2) = t31; *(bb1 + 3) = t41;
            *(bb2 + 0) = t12; *(bb2 + 1) = t22; *(bb2 + 2) = t32; *(bb2 + 3) = t42;
            *(cc1 + 0) = t11; *(cc1 + 1) = t21; *(cc1 + 2) = t12; *(cc1 + 3) = t22;
            *(cc2 + 0) = t31; *(cc2 + 1) = t41; *(cc2 + 2) = t32; *(cc2 + 3) = t42;

            aa1 += 4; aa2 += 4;
            bb1 += 4; bb2 += 4;
            cc1 += 4 * m; cc2 += 4 * m;
        }

        if (m & 1) {
            float x11 = *(aa1 + 0), x21 = *(aa1 + 1);
            float x12 = *(aa2 + 0), x22 = *(aa2 + 1);

            *(bb1 + 0) = x11; *(bb1 + 1) = x21;
            *(bb2 + 0) = x12; *(bb2 + 1) = x22;
            *(cc1 + 0) = x11; *(cc1 + 1) = x21;
            *(cc1 + 2) = x12; *(cc1 + 3) = x22;
        }
    }

    if (m - js == 1) {
        float val1 = *(aa1 + 0), val2 = *(aa1 + 1);
        *(bb1 + 0) = val1;
        *(bb1 + 1) = val2;
    }
}
}
