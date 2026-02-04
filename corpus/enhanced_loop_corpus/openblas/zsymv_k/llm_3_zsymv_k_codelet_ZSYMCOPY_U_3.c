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
    BLASLONG idx_b = 0;
    for (is = 0; is < js; is += 2) {
        float temp_block_a[8];
        float temp_block_b[8];
        temp_block_a[0] = *(aa1 + 0);
        temp_block_a[1] = *(aa1 + 1);
        temp_block_a[2] = *(aa1 + 2);
        temp_block_a[3] = *(aa1 + 3);
        temp_block_a[4] = *(aa2 + 0);
        temp_block_a[5] = *(aa2 + 1);
        temp_block_a[6] = *(aa2 + 2);
        temp_block_a[7] = *(aa2 + 3);
        temp_block_b[0] = temp_block_a[0];
        temp_block_b[1] = temp_block_a[1];
        temp_block_b[2] = temp_block_a[2];
        temp_block_b[3] = temp_block_a[3];
        temp_block_b[4] = temp_block_a[4];
        temp_block_b[5] = temp_block_a[5];
        temp_block_b[6] = temp_block_a[6];
        temp_block_b[7] = temp_block_a[7];
        for (idx_b = 0; idx_b < 4; idx_b++) {
            *(b1 + is*m + 0*m + idx_b) = temp_block_b[idx_b];
            *(b1 + is*m + 2*m + idx_b) = temp_block_b[4 + idx_b];
        }
        for (idx_b = 0; idx_b < 2; idx_b++) {
            *(b2 + is*m + 0*m + idx_b*2*m) = temp_block_a[idx_b];
            *(b2 + is*m + 0*m + idx_b*2*m + 1) = temp_block_a[idx_b + 1];
            *(b2 + is*m + 2*m + idx_b*2*m) = temp_block_a[idx_b + 4];
            *(b2 + is*m + 2*m + idx_b*2*m + 1) = temp_block_a[idx_b + 5];
        }
        aa1 += 4;
        aa2 += 4;
    }
    if (m - js >= 2) {
        a11 = *(aa1 + 0);
        a21 = *(aa1 + 1);
        a12 = *(aa2 + 0);
        a22 = *(aa2 + 1);
        a32 = *(aa2 + 2);
        a42 = *(aa2 + 3);
        *(b1 + js*m + 0) = a11;
        *(b1 + js*m + 1) = a21;
        *(b1 + js*m + 2) = a12;
        *(b1 + js*m + 3) = a22;
        *(b1 + (js+1)*m + 0) = a12;
        *(b1 + (js+1)*m + 1) = a22;
        *(b1 + (js+1)*m + 2) = a32;
        *(b1 + (js+1)*m + 3) = a42;
    }
    if (m - js == 1) {
        for (is = 0; is < js; is += 2) {
            a11 = *(aa1 + 0);
            a21 = *(aa1 + 1);
            a31 = *(aa1 + 2);
            a41 = *(aa1 + 3);
            *(b1 + is*m + 0) = a11;
            *(b1 + is*m + 1) = a21;
            *(b1 + is*m + 2) = a31;
            *(b1 + is*m + 3) = a41;
            *(b2 + is*m + 0) = a11;
            *(b2 + is*m + 1) = a21;
            *(b2 + is*m + 2*m) = a31;
            *(b2 + is*m + 2*m + 1) = a41;
            aa1 += 4;
        }
        a11 = *(aa1 + 0);
        a21 = *(aa1 + 1);
        *(b1 + js*m + 0) = a11;
        *(b1 + js*m + 1) = a21;
    }
}
}
