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

    for (BLASLONG k = 0; k < m - js && k < 4; k += 2) {
        if (k + 1 < 4 && js + k + 1 < m) {
            a11 = *(aa1 + 0);
            a21 = *(aa1 + 1);
            a22 = *(aa2 + 1);
            *(bb1 + 0) = a11;
            *(bb1 + 1) = a21;
            *(bb2 + 0) = a21;
            *(bb2 + 1) = a22;

            aa1 += 2;
            aa2 += 2;
            bb1 += 2;
            bb2 += 2;
            cc1 += 2 * m;
            cc2 += 2 * m;

            if (m - js - k > 2) {
                BLASLONG inner_end = (m - js - k - 2) >= 2 ? 2 : (m - js - k - 2);
                for (BLASLONG i = 0; i < inner_end; ++i) {
                    a11 = *(aa1 + 0);
                    a21 = *(aa1 + 1);
                    a12 = *(aa2 + 0);
                    a22 = *(aa2 + 1);
                    aa1 += 2;
                    aa2 += 2;
                    *(bb1 + 0) = a11;
                    *(bb1 + 1) = a21;
                    *(bb2 + 0) = a12;
                    *(bb2 + 1) = a22;
                    *(cc1 + 0) = a11;
                    *(cc1 + 1) = a12;
                    *(cc2 + 0) = a21;
                    *(cc2 + 1) = a22;
                    bb1 += 2;
                    bb2 += 2;
                    cc1 += 2 * m;
                    cc2 += 2 * m;
                }
            }

            if ((m - js - k - 2) & 1) {
                a11 = *(aa1 + 0);
                a12 = *(aa2 + 0);
                *(bb1 + 0) = a11;
                *(bb2 + 0) = a12;
                *(cc1 + 0) = a11;
                *(cc1 + 1) = a12;
            }
        } else if (k < m - js) {
            a11 = *(aa1 + 0);
            *(bb1 + 0) = a11;
        }
    }
}
}
