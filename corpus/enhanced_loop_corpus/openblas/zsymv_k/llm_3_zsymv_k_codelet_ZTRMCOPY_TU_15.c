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
    bb1 = b1 + 0;
    bb2 = b1 + 2 * m;
    b1 += 4 * m;
    cc1 = b2 + 0;
    cc2 = b2 + 2;
    b2 += 4;
    if (m - js >= 2) {
        for (is = 0; is < js; is += 2) {
            float temp_load[8];
            temp_load[0] = aa1[0]; temp_load[1] = aa1[1];
            temp_load[2] = aa1[2]; temp_load[3] = aa1[3];
            temp_load[4] = aa2[0]; temp_load[5] = aa2[1];
            temp_load[6] = aa2[2]; temp_load[7] = aa2[3];
            aa1 += 4;
            aa2 += 4;
            float *dest_b1 = bb1 + idx_b;
            float *dest_b2 = bb2 + idx_b;
            dest_b1[0] = temp_load[0]; dest_b1[1] = temp_load[1];
            dest_b1[2] = temp_load[2]; dest_b1[3] = temp_load[3];
            dest_b2[0] = temp_load[4]; dest_b2[1] = temp_load[5];
            dest_b2[2] = temp_load[6]; dest_b2[3] = temp_load[7];
            cc1[0] = temp_load[0]; cc1[m] = temp_load[1];
            cc1[1] = temp_load[4]; cc1[m+1] = temp_load[5];
            cc2[0] = temp_load[2]; cc2[m] = temp_load[3];
            cc2[1] = temp_load[6]; cc2[m+1] = temp_load[7];
            idx_b += 4;
            cc1 += 4 * m;
            cc2 += 4 * m;
        }
        a11 = aa1[0]; a21 = aa1[1];
        a12 = aa2[0]; a22 = aa2[1];
        a32 = aa2[2]; a42 = aa2[3];
        bb1[0] = a11; bb1[1] = a21;
        bb1[2] = a12; bb1[3] = a22;
        bb2[0] = a12; bb2[1] = a22;
        bb2[2] = a32; bb2[3] = a42;
    }
    if (m - js == 1) {
        BLASLONG idx_single = 0;
        for (is = 0; is < js; is += 2) {
            a11 = *(aa1 + 0); a21 = *(aa1 + 1);
            a31 = *(aa1 + 2); a41 = *(aa1 + 3);
            aa1 += 4;
            float *dest = bb1 + idx_single;
            dest[0] = a11; dest[1] = a21;
            dest[2] = a31; dest[3] = a41;
            cc1[idx_single] = a11; cc1[idx_single + m] = a21;
            cc2[idx_single] = a31; cc2[idx_single + m] = a41;
            idx_single += 4;
            cc1 += 4 * m;
            cc2 += 4 * m;
        }
        a11 = *(aa1 + 0); a21 = *(aa1 + 1);
        bb1[js] = a11; bb1[js+1] = a21;
    }
}
}
