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
extern float a12;
extern float a21;
extern float a22;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (js = 0; js < m; js += 4) {
    aa1 = a + 0 * lda;
    aa2 = a + 1 * lda;
    a += 4 * lda + 4;
    bb1 = b1 + 0 * m;
    bb2 = b1 + 1 * m;
    b1 += 4 * m + 4;
    cc1 = b2 + 0 * m;
    cc2 = b2 + 1 * m;
    b2 += 4 * m + 4;

    BLASLONG rem = m - js;
    if (rem >= 4) {
        for (BLASLONG k = 0; k < 4; ++k) {
            a11 = *(aa1 + 0);
            a21 = *(aa1 + 1);
            a12 = *(aa2 + 0);
            a22 = *(aa2 + 1);

            *(bb1 + 0) = a11;
            *(bb1 + 1) = a21;
            *(bb2 + 0) = a12;
            *(bb2 + 1) = a22;
            *(cc1 + 0) = a11;
            *(cc1 + 1) = a12;
            *(cc2 + 0) = a21;
            *(cc2 + 1) = a22;

            aa1 += 2;
            aa2 += 2;
            bb1 += 2;
            bb2 += 2;
            cc1 += 2 * m;
            cc2 += 2 * m;
        }
        for (BLASLONG k = 0; k < ((m - js - 4) / 2); ++k) {
            a11 = *(aa1 + 0);
            a21 = *(aa1 + 1);
            a12 = *(aa2 + 0);
            a22 = *(aa2 + 1);

            *(bb1 + 0) = a11;
            *(bb1 + 1) = a21;
            *(bb2 + 0) = a12;
            *(bb2 + 1) = a22;
            *(cc1 + 0) = a11;
            *(cc1 + 1) = a12;
            *(cc2 + 0) = a21;
            *(cc2 + 1) = a22;

            aa1 += 2;
            aa2 += 2;
            bb1 += 2;
            bb2 += 2;
            cc1 += 2 * m;
            cc2 += 2 * m;
        }
        BLASLONG tail = (m - js - 4) & 1;
        if (tail) {
            a11 = *(aa1 + 0);
            a12 = *(aa2 + 0);
            *(bb1 + 0) = a11;
            *(bb2 + 0) = a12;
            *(cc1 + 0) = a11;
            *(cc1 + 1) = a12;
        }
    } else {
        for (BLASLONG k = 0; k < rem; ++k) {
            if (k == 0) {
                a11 = *(aa1 + 0);
                *(bb1 + 0) = a11;
            } else if (k == 1) {
                a21 = *(aa1 + 1);
                *(bb1 + 1) = a21;
                *(bb2 + 0) = a21;
            } else if (k == 2) {
                a12 = *(aa2 + 0);
                *(bb2 + 0) = a12;
                *(cc1 + 0) = a11;
                *(cc1 + 1) = a12;
            } else if (k == 3) {
                a22 = *(aa2 + 1);
                *(bb2 + 1) = a22;
                *(cc2 + 0) = a21;
                *(cc2 + 1) = a22;
            }
        }
    }
}
}
