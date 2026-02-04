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
        for (BLASLONG offset = 0; offset < 4; ++offset) {
            ((float*)bb1)[offset] = aa1[offset];
            ((float*)bb2)[offset] = (offset < 2) ? aa1[offset + 2] : aa2[offset];
        }

        BLASLONG remaining = (m - js - 2) >> 1;
        for (is = 0; is < remaining; ++is) {
            a11 = aa1[0]; a21 = aa1[1]; a31 = aa1[2]; a41 = aa1[3];
            a12 = aa2[0]; a22 = aa2[1]; a32 = aa2[2]; a42 = aa2[3];

            ((float*)bb1)[0] = a11; ((float*)bb1)[1] = a21;
            ((float*)bb1)[2] = a31; ((float*)bb1)[3] = a41;

            ((float*)bb2)[0] = a12; ((float*)bb2)[1] = a22;
            ((float*)bb2)[2] = a32; ((float*)bb2)[3] = a42;

            ((float*)cc1)[0] = a11; ((float*)cc1)[1] = a21;
            ((float*)cc1)[2] = a12; ((float*)cc1)[3] = a22;

            ((float*)cc2)[0] = a31; ((float*)cc2)[1] = a41;
            ((float*)cc2)[2] = a32; ((float*)cc2)[3] = a42;

            aa1 += 4; aa2 += 4;
            bb1 += 4; bb2 += 4;
            cc1 += 4 * m; cc2 += 4 * m;
        }

        if (m & 1) {
            a11 = aa1[0]; a21 = aa1[1];
            a12 = aa2[0]; a22 = aa2[1];

            ((float*)bb1)[0] = a11; ((float*)bb1)[1] = a21;
            ((float*)bb2)[0] = a12; ((float*)bb2)[1] = a22;

            ((float*)cc1)[0] = a11; ((float*)cc1)[1] = a21;
            ((float*)cc1)[2] = a12; ((float*)cc1)[3] = a22;
        }
    }

    if (m - js == 1) {
        ((float*)bb1)[0] = aa1[0];
        ((float*)bb1)[1] = aa1[1];
    }
}
}
