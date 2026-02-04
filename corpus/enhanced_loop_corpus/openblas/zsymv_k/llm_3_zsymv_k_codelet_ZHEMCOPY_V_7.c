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
    BLASLONG offset_a1 = 0 * lda;
    BLASLONG offset_a2 = 1 * lda;
    aa1 = a + offset_a1;
    aa2 = a + offset_a2;
    a += 2 * lda;
    BLASLONG idx_b = js * 2;
    bb1 = b1 + (idx_b + 0) % (4 * m);
    bb2 = b1 + (idx_b + 2) % (4 * m);
    b1 += 4 * m;
    cc1 = b2 + (idx_b + 0) % (4 * m);
    cc2 = b2 + (idx_b + 2) % (4 * m);
    b2 += 4;
    if (m - js >= 2) {
        for (is = 0; is < js; is += 2) {
            BLASLONG idx_aa = is * 2;
            a11 = *(aa1 + (idx_aa + 0));
            a21 = *(aa1 + (idx_aa + 1));
            a31 = *(aa1 + (idx_aa + 2));
            a41 = *(aa1 + (idx_aa + 3));
            a12 = *(aa2 + (idx_aa + 0));
            a22 = *(aa2 + (idx_aa + 1));
            a32 = *(aa2 + (idx_aa + 2));
            a42 = *(aa2 + (idx_aa + 3));
            *(bb1 + (is % 4)) = a11;
            *(bb1 + ((is + 1) % 4)) = -a21;
            *(bb1 + ((is + 2) % 4)) = a31;
            *(bb1 + ((is + 3) % 4)) = -a41;
            *(bb2 + (is % 4)) = a12;
            *(bb2 + ((is + 1) % 4)) = -a22;
            *(bb2 + ((is + 2) % 4)) = a32;
            *(bb2 + ((is + 3) % 4)) = -a42;
            *(cc1 + (is % 4)) = a11;
            *(cc1 + ((is + 1) % 4)) = a21;
            *(cc1 + ((is + 2) % 4)) = a12;
            *(cc1 + ((is + 3) % 4)) = a22;
            *(cc2 + (is % 4)) = a31;
            *(cc2 + ((is + 1) % 4)) = a41;
            *(cc2 + ((is + 2) % 4)) = a32;
            *(cc2 + ((is + 3) % 4)) = a42;
        }
        a11 = *(aa1 + 0);
        a12 = *(aa2 + 0);
        a22 = *(aa2 + 1);
        a32 = *(aa2 + 2);
        *(bb1 + 0) = a11;
        *(bb1 + 1) = 0.0f;
        *(bb1 + 2) = a12;
        *(bb1 + 3) = a22;
        *(bb2 + 0) = a12;
        *(bb2 + 1) = -a22;
        *(bb2 + 2) = a32;
        *(bb2 + 3) = 0.0f;
    }
    if (m - js == 1) {
        for (is = 0; is < js; is += 2) {
            a11 = *(aa1 + is * 2 + 0);
            a21 = *(aa1 + is * 2 + 1);
            a31 = *(aa1 + is * 2 + 2);
            a41 = *(aa1 + is * 2 + 3);
            *(bb1 + (is % 4)) = a11;
            *(bb1 + ((is + 1) % 4)) = -a21;
            *(bb1 + ((is + 2) % 4)) = a31;
            *(bb1 + ((is + 3) % 4)) = -a41;
            *(cc1 + (is % 4)) = a11;
            *(cc1 + ((is + 1) % 4)) = a21;
            *(cc2 + (is % 4)) = a31;
            *(cc2 + ((is + 1) % 4)) = a41;
        }
        a11 = *(aa1 + 0);
        *(bb1 + 0) = a11;
        *(bb1 + 1) = 0.0f;
    }
}
}
