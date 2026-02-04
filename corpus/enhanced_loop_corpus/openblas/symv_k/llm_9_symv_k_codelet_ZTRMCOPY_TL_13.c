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
for (js = 0; js < m && (m - js) >= 2; js += 2) {
    aa1 = a + 0 * lda;
    aa2 = a + 1 * lda;
    a += 2 * lda;

    bb1 = b1 + js * m;
    bb2 = b1 + (js + 1) * m;
    cc1 = b2 + js * m;
    cc2 = b2 + (js + 1) * m;

    for (is = 0; is < m; is += 8) {
        if (is + 4 <= m) {
            a11 = *(aa1 + is + 0); a21 = *(aa1 + is + 1);
            a31 = *(aa1 + is + 2); a41 = *(aa1 + is + 3);
            a12 = *(aa2 + is + 0); a22 = *(aa2 + is + 1);
            float a32 = *(aa2 + is + 2), a42 = *(aa2 + is + 3);

            *(bb1 + is + 0) = a11; *(bb1 + is + 1) = a21;
            *(bb1 + is + 2) = a31; *(bb1 + is + 3) = a41;
            *(bb2 + is + 0) = a12; *(bb2 + is + 1) = a22;
            *(bb2 + is + 2) = a32; *(bb2 + is + 3) = a42;

            *(cc1 + is + 0) = a11; *(cc1 + is + 1) = a21;
            *(cc1 + is + 2) = a12; *(cc1 + is + 3) = a22;
            *(cc2 + is + 0) = a31; *(cc2 + is + 1) = a41;
            *(cc2 + is + 2) = a32; *(cc2 + is + 3) = a42;
        }

        if (is + 8 <= m) {
            a11 = *(aa1 + is + 4); a21 = *(aa1 + is + 5);
            a31 = *(aa1 + is + 6); a41 = *(aa1 + is + 7);
            a12 = *(aa2 + is + 4); a22 = *(aa2 + is + 5);
            float a32 = *(aa2 + is + 6), a42 = *(aa2 + is + 7);

            *(bb1 + is + 4) = a11; *(bb1 + is + 5) = a21;
            *(bb1 + is + 6) = a31; *(bb1 + is + 7) = a41;
            *(bb2 + is + 4) = a12; *(bb2 + is + 5) = a22;
            *(bb2 + is + 6) = a32; *(bb2 + is + 7) = a42;

            *(cc1 + is + 4) = a11; *(cc1 + is + 5) = a21;
            *(cc1 + is + 6) = a12; *(cc1 + is + 7) = a22;
            *(cc2 + is + 4) = a31; *(cc2 + is + 5) = a41;
            *(cc2 + is + 6) = a32; *(cc2 + is + 7) = a42;
        }
    }
}

if (m & 1) {
    js = m - 1;
    aa1 = a + 0 * lda;
    bb1 = b1 + js * m;
    for (is = 0; is < m; is++) {
        *(bb1 + is) = *(aa1 + is);
    }
}
}
