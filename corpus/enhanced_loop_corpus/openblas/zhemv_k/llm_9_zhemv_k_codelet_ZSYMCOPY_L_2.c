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
for (js = 0; js < m; js++) {
    aa1 = a + (js % 2) * lda;
    bb1 = b1 + (js % 4) * m;
    cc1 = b2 + (js % 4) * m;

    for (is = 0; is < m; is += 8) {
        if (is + 8 <= m) {
            float temp[8];
            for (BLASLONG k = 0; k < 8; k++) {
                temp[k] = *(aa1 + is + k);
            }

            *(bb1 + is + 0) = temp[0]; *(bb1 + is + 1) = temp[1];
            *(bb1 + is + 2) = temp[2]; *(bb1 + is + 3) = temp[3];
            *(bb1 + is + 4) = temp[4]; *(bb1 + is + 5) = temp[5];
            *(bb1 + is + 6) = temp[6]; *(bb1 + is + 7) = temp[7];

            *(cc1 + is + 0) = temp[0]; *(cc1 + is + 1) = temp[1];
            *(cc1 + is + 2) = temp[2]; *(cc1 + is + 3) = temp[3];
            *(cc1 + is + 4) = temp[4]; *(cc1 + is + 5) = temp[5];
            *(cc1 + is + 6) = temp[6]; *(cc1 + is + 7) = temp[7];
        } else {
            for (BLASLONG k = is; k < m; k++) {
                float val = *(aa1 + k);
                *(bb1 + k) = val;
                *(cc1 + k) = val;
            }
        }
    }

    if (js % 2 == 1) {
        a += lda + 2;
        b1 += 2 * m + 2;
        b2 += 2 * m + 2;
    }
}
}
