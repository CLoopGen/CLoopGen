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
    if (m - js >= 4) {
        aa1 = a + 0 * lda;
        aa2 = a + 1 * lda;
        BLASLONG lda2 = lda * 2;
        a += 4 * lda;
        bb1 = b1 + 0 * m;
        bb2 = b1 + 1 * m;
        b1 += 4 * m;
        cc1 = b2 + 0 * m;
        cc2 = b2 + 1 * m;
        b2 += 4;
        for (is = 0; is < js; is += 4) {
            float temp_a[8];
            temp_a[0] = *(aa1 + 0); temp_a[1] = *(aa1 + 1);
            temp_a[2] = *(aa1 + 2); temp_a[3] = *(aa1 + 3);
            temp_a[4] = *(aa2 + 0); temp_a[5] = *(aa2 + 1);
            temp_a[6] = *(aa2 + 2); temp_a[7] = *(aa2 + 3);
            aa1 += 4; aa2 += 4;

            *(bb1 + 0) = temp_a[0]; *(bb1 + 1) = temp_a[1];
            *(bb1 + 2) = temp_a[2]; *(bb1 + 3) = temp_a[3];
            *(bb2 + 0) = temp_a[4]; *(bb2 + 1) = temp_a[5];
            *(bb2 + 2) = temp_a[6]; *(bb2 + 3) = temp_a[7];

            *(cc1 + 0) = temp_a[0]; *(cc1 + 1) = temp_a[4];
            *(cc1 + 2*m) = temp_a[1]; *(cc1 + 2*m+1) = temp_a[5];
            *(cc2 + 0) = temp_a[2]; *(cc2 + 1) = temp_a[6];
            *(cc2 + 2*m) = temp_a[3]; *(cc2 + 2*m+1) = temp_a[7];

            bb1 += 4; bb2 += 4;
            cc1 += 4 * m; cc2 += 4 * m;
        }
        a11 = *(aa1 + 0); a12 = *(aa2 + 0);
        a21 = *(aa1 + 1); a22 = *(aa2 + 1);
        *(bb1 + 0) = a11; *(bb1 + 1) = a21;
        *(bb1 + 2) = a12; *(bb1 + 3) = a22;
        *(bb2 + 0) = a12; *(bb2 + 1) = a22;
    } else {
        for (; js < m; js++) {
            aa1 = a;
            a += lda;
            bb1 = b1 + js * m;
            cc1 = b2 + js * m;
            for (is = 0; is < js; is++) {
                float val = *(aa1 + is);
                *(bb1 + is) = val;
                *(cc1 + is) = val;
            }
            if (js < m) {
                *(bb1 + js) = *(aa1 + js);
            }
        }
    }
}
}
