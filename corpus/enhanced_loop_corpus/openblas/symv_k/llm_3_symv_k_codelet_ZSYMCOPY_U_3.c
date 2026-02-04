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
    BLASLONG offset_a = 0 * lda;
    BLASLONG offset_aa = 1 * lda;
    aa1 = a + offset_a;
    aa2 = a + offset_aa;
    a += 2 * lda;
    BLASLONG idx_b = 0;
    bb1 = b1 + idx_b;
    bb2 = b1 + 2 * m;
    b1 += 4 * m;
    BLASLONG idx_c = 0;
    cc1 = b2 + idx_c;
    cc2 = b2 + 2 * m;
    b2 += 4;
    if (m - js >= 2) {
        for (is = 0; is < js; is += 2) {
            float temp_A[8] = {
                *(aa1 + 0), *(aa1 + 1), *(aa1 + 2), *(aa1 + 3),
                *(aa2 + 0), *(aa2 + 1), *(aa2 + 2), *(aa2 + 3)
            };
            a11 = temp_A[0]; a21 = temp_A[1]; a31 = temp_A[2]; a41 = temp_A[3];
            a12 = temp_A[4]; a22 = temp_A[5]; a32 = temp_A[6]; a42 = temp_A[7];
            aa1 += 4;
            aa2 += 4;
            float *dest_b1 = &bb1[0], *dest_b2 = &bb2[0];
            for (int k = 0; k < 4; ++k) {
                dest_b1[k] = temp_A[k];
                dest_b2[k] = temp_A[k + 4];
            }
            cc1[0] = a11; cc1[m] = a21; cc1[2*m] = a12; cc1[3*m] = a22;
            cc2[0] = a31; cc2[m] = a41; cc2[2*m] = a32; cc2[3*m] = a42;
            bb1 += 4;
            bb2 += 4;
            cc1 += 4;
            cc2 += 4;
        }
        a11 = *(aa1 + 0);
        a21 = *(aa1 + 1);
        a12 = *(aa2 + 0);
        a22 = *(aa2 + 1);
        a32 = *(aa2 + 2);
        a42 = *(aa2 + 3);
        bb1[0] = a11; bb1[1] = a21; bb1[2] = a12; bb1[3] = a22;
        bb2[0] = a12; bb2[1] = a22; bb2[2] = a32; bb2[3] = a42;
    }
    if (m - js == 1) {
        for (is = 0; is < js; is += 2) {
            a11 = *(aa1 + 0);
            a21 = *(aa1 + 1);
            a31 = *(aa1 + 2);
            a41 = *(aa1 + 3);
            aa1 += 4;
            bb1[0] = a11; bb1[1] = a21; bb1[2] = a31; bb1[3] = a41;
            cc1[0] = a11; cc1[m] = a21;
            cc2[0] = a31; cc2[m] = a41;
            bb1 += 4;
            cc1 += 4;
            cc2 += 4;
        }
        a11 = *(aa1 + 0);
        a21 = *(aa1 + 1);
        bb1[0] = a11;
        bb1[1] = a21;
    }
}
}
