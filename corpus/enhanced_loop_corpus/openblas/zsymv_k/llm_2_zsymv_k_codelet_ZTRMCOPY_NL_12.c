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
        for (BLASLONG offset = 0; offset < 4; offset++) {
            *(bb1 + offset) = *(aa1 + offset);
            *(bb2 + offset) = (offset < 2) ? *(aa1 + 2 + offset) : *(aa2 + offset - 2);
        }

        BLASLONG remaining = (m - js - 2) / 2;
        for (BLASLONG k = 0; k < remaining; k++) {
            for (BLASLONG i = 0; i < 4; i++) {
                float temp1 = *(aa1 + i);
                float temp2 = *(aa2 + i);
                *(bb1 + i) = temp1;
                *(bb2 + i) = temp2;
                *(cc1 + i) = (i < 2) ? temp1 : temp2;
                *(cc2 + i) = (i < 2) ? *(aa1 + i + 2) : *(aa2 + i - 2);
            }
            aa1 += 4;
            aa2 += 4;
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
