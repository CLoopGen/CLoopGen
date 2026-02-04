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
    aa1 = a;
    aa2 = a + lda;
    a += 2 * lda + 4;
    bb1 = b1;
    bb2 = b1 + 2 * m;
    b1 += 4 * m + 4;
    cc1 = b2;
    cc2 = b2 + 2 * m;
    b2 += 4 * m + 4;

    if (m - js >= 2) {
        float block_a[8];
        float block_b[8];
        
        for (BLASLONG i = 0; i < 4; i++) {
            block_a[i]     = *(aa1 + i);
            block_a[4 + i] = *(aa2 + i);
        }

        for (BLASLONG i = 0; i < 4; i++) {
            *(bb1 + i) = block_a[i];
            *(bb2 + i) = (i < 2) ? block_a[2 + i] : block_a[2 + i];
        }

        BLASLONG inner_iters = (m - js - 2) / 2;
        for (BLASLONG k = 0; k < inner_iters; k++) {
            for (BLASLONG i = 0; i < 4; i++) {
                block_a[i] = *(aa1 + i);
                block_b[i] = *(aa2 + i);
            }
            aa1 += 4;
            aa2 += 4;

            for (BLASLONG i = 0; i < 4; i++) {
                *(bb1 + i) = block_a[i];
                *(bb2 + i) = block_b[i];
                *(cc1 + i) = (i % 2 == 0) ? block_a[i/2] : block_b[i/2];
                *(cc2 + i) = (i % 2 == 0) ? block_a[2 + i/2] : block_b[2 + i/2];
            }

            bb1 += 4;
            bb2 += 4;
            cc1 += 4 * m;
            cc2 += 4 * m;
        }

        if (m & 1) {
            *(bb1 + 0) = *(aa1 + 0);
            *(bb1 + 1) = *(aa1 + 1);
            *(bb2 + 0) = *(aa2 + 0);
            *(bb2 + 1) = *(aa2 + 1);
            *(cc1 + 0) = *(aa1 + 0);
            *(cc1 + 1) = *(aa1 + 1);
            *(cc1 + 2) = *(aa2 + 0);
            *(cc1 + 3) = *(aa2 + 1);
        }
    }

    if (m - js == 1) {
        *(bb1 + 0) = *(aa1 + 0);
        *(bb1 + 1) = *(aa1 + 1);
    }
}
}
