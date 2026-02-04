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
        float temp_a31 = *(aa1 + 2);
        float temp_a41 = *(aa1 + 3);
        float temp_a12 = *(aa2 + 2);
        *(bb1 + 0) = temp_a11;
        *(bb1 + 1) = 0.0f;
        *(bb1 + 2) = temp_a31;
        *(bb1 + 3) = temp_a41;
        *(bb2 + 0) = temp_a31;
        *(bb2 + 1) = -temp_a41;
        *(bb2 + 2) = temp_a12;
        *(bb2 + 3) = 0.0f;
        aa1 += 4;
        aa2 += 4;
        bb1 += 4;
        bb2 += 4;
        cc1 += 4 * m;
        cc2 += 4 * m;
        BLASLONG trip_count = (m - js - 2 + 1) / 2;
        for (is = 0; is < trip_count; is++) {
            float r11, r12, r13, r14;
            float r21, r22, r23, r24;
            r11 = *(aa1 + 0); r12 = *(aa1 + 1);
            r13 = *(aa1 + 2); r14 = *(aa1 + 3);
            r21 = *(aa2 + 0); r22 = *(aa2 + 1);
            r23 = *(aa2 + 2); r24 = *(aa2 + 3);
            *(bb1 + 0) = r11; *(bb1 + 1) = r12;
            *(bb1 + 2) = r13; *(bb1 + 3) = r14;
            *(bb2 + 0) = r21; *(bb2 + 1) = r22;
            *(bb2 + 2) = r23; *(bb2 + 3) = r24;
            *(cc1 + 0) = r11; *(cc1 + 1) = -r12;
            *(cc1 + 2) = r21; *(cc1 + 3) = -r22;
            *(cc2 + 0) = r13; *(cc2 + 1) = -r14;
            *(cc2 + 2) = r23; *(cc2 + 3) = -r24;
            aa1 += 4; aa2 += 4;
            bb1 += 4; bb2 += 4;
            cc1 += 4 * m; cc2 += 4 * m;
        }
        if (m & 1) {
            float x11 = *(aa1 + 0), x21 = *(aa1 + 1);
            float x12 = *(aa2 + 0), x22 = *(aa2 + 1);
            *(bb1 + 0) = x11; *(bb1 + 1) = x21;
            *(bb2 + 0) = x12; *(bb2 + 1) = x22;
            *(cc1 + 0) = x11; *(cc1 + 1) = -x21;
            *(cc1 + 2) = x12; *(cc1 + 3) = -x22;
        }
    }
    else if (m - js == 1) {
        float val = *(aa1 + 0);
        *(bb1 + 0) = val;
        *(bb1 + 1) = 0.0f;
    }
}
}
