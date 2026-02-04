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
    BLASLONG idx_b1 = 0, idx_b2 = 2;
    bb1 = b1 + idx_b1 * m;
    bb2 = b1 + idx_b2 * m;
    b1 += 4 * m;
    BLASLONG idx_c1 = 0, idx_c2 = 2;
    cc1 = b2 + idx_c1 * m;
    cc2 = b2 + idx_c2 * m;
    b2 += 4;
    if (m - js >= 2) {
        for (is = 0; is < js; is += 2) {
            float temp_a[8] = {
                *(aa1 + 0), *(aa1 + 1), *(aa1 + 2), *(aa1 + 3),
                *(aa2 + 0), *(aa2 + 1), *(aa2 + 2), *(aa2 + 3)
            };
            a11 = temp_a[0]; a21 = temp_a[1]; a31 = temp_a[2]; a41 = temp_a[3];
            a12 = temp_a[4]; a22 = temp_a[5]; a32 = temp_a[6]; a42 = temp_a[7];
            aa1 += 4;
            aa2 += 4;
            float *dest_b1 = bb1;
            float *dest_b2 = bb2;
            dest_b1[0] = a11; dest_b1[1] = a21; dest_b1[2] = a31; dest_b1[3] = a41;
            dest_b2[0] = a12; dest_b2[1] = a22; dest_b2[2] = a32; dest_b2[3] = a42;
            float *dest_c1 = cc1;
            float *dest_c2 = cc2;
            dest_c1[0] = a11; dest_c1[1] = -a21; dest_c1[m] = a12; dest_c1[m+1] = -a22;
            dest_c2[0] = a31; dest_c2[1] = -a41; dest_c2[m] = a32; dest_c2[m+1] = -a42;
            bb1 += 4;
            bb2 += 4;
            cc1 += 4 * m;
            cc2 += 4 * m;
        }
        a11 = *(aa1 + 0);
        a12 = *(aa2 + 0);
        a22 = *(aa2 + 1);
        a32 = *(aa2 + 2);
        bb1[0] = a11; bb1[1] = 0.0f; bb1[2] = a12; bb1[3] = -a22;
        bb2[0] = a12; bb2[1] = a22; bb2[2] = a32; bb2[3] = 0.0f;
    }
    if (m - js == 1) {
        for (is = 0; is < js; is += 2) {
            a11 = *(aa1 + 0);
            a21 = *(aa1 + 1);
            a31 = *(aa1 + 2);
            a41 = *(aa1 + 3);
            aa1 += 4;
            bb1[0] = a11; bb1[1] = a21; bb1[2] = a31; bb1[3] = a41;
            cc1[0] = a11; cc1[1] = -a21;
            cc2[0] = a31; cc2[1] = -a41;
            bb1 += 4;
            cc1 += 4 * m;
            cc2 += 4 * m;
        }
        a11 = *(aa1 + 0);
        bb1[0] = a11;
        bb1[1] = 0.0f;
    }
}
}
