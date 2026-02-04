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
for (js = 0; js < m; js += 2) {
    aa1 = a + 0 * lda;
    aa2 = a + 1 * lda;
    a += 2 * lda + 2;
    bb1 = b1 + 0 * m;
    bb2 = b1 + 1 * m;
    b1 += 2 * m + 2;
    cc1 = b2 + 0 * m;
    cc2 = b2 + 1 * m;
    b2 += 2 * m + 2;

    if (m - js >= 2) {
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

        BLASLONG trip_count = (m - js - 2);
        for (is = 0; is < trip_count; is++) {
            float val1 = *(aa1 + (is % 2));
            float val2 = *(aa1 + (is % 2) + 1);
            float val3 = *(aa2 + (is % 2));
            float val4 = *(aa2 + (is % 2) + 1);

            if ((is & 1) == 0 && is + 1 < trip_count) {
                *(bb1 + 0) = val1;
                *(bb1 + 1) = val2;
                *(bb2 + 0) = val3;
                *(bb2 + 1) = val4;

                *(cc1 + 0) = val1;
                *(cc1 + 1) = val3;
                *(cc2 + 0) = val2;
                *(cc2 + 1) = val4;

                bb1 += 2;
                bb2 += 2;
                cc1 += 2 * m;
                cc2 += 2 * m;
                aa1 += 2;
                aa2 += 2;
            } else if (is == trip_count - 1) {
                *(bb1 + 0) = val1;
                *(bb2 + 0) = val3;
                *(cc1 + 0) = val1;
                *(cc1 + 1) = val3;
            }
        }
    }

    if (m - js == 1) {
        a11 = *(aa1 + 0);
        *(bb1 + 0) = a11;
    }
}
}
