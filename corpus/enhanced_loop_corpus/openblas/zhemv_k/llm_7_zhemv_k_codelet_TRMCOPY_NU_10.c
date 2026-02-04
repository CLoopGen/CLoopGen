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
    a += 2 * lda;
    bb1 = b1 + 0 * m;
    bb2 = b1 + 1 * m;
    b1 += 2 * m;
    cc1 = b2 + 0 * m;
    cc2 = b2 + 1 * m;
    b2 += 2;
    if (m - js >= 2) {
        // Eliminate loop-carried dependency by unrolling assumption and using temporaries
        float temp_a11[8], temp_a12[8], temp_a21[8], temp_a22[8];
        BLASLONG count = 0;
        for (is = 0; is < js && count < 8; is += 2, count++) {
            temp_a11[count] = *(aa1 + 0);
            temp_a21[count] = *(aa1 + 1);
            temp_a12[count] = *(aa2 + 0);
            temp_a22[count] = *(aa2 + 1);
            aa1 += 2;
            aa2 += 2;
        }
        // Now replay buffered values — introduces WAW on original arrays but removes RAW across iterations
        BLASLONG k;
        for (k = 0; k < count; k++) {
            *(bb1 + 0) = temp_a11[k];
            *(bb1 + 1) = temp_a21[k];
            *(bb2 + 0) = temp_a12[k];
            *(bb2 + 1) = temp_a22[k];
            *(cc1 + 0) = temp_a11[k];
            *(cc1 + 1) = temp_a12[k];
            *(cc2 + 0) = temp_a21[k];
            *(cc2 + 1) = temp_a22[k];
            bb1 += 2;
            bb2 += 2;
            cc1 += 2 * m;
            cc2 += 2 * m;
        }
        // Handle leftover iterations normally if any
        for (; is < js; is += 2) {
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
        a11 = *(aa1 + 0);
        a12 = *(aa2 + 0);
        a22 = *(aa2 + 1);
        *(bb1 + 0) = a11;
        *(bb1 + 1) = a12;
        *(bb2 + 0) = a12;
        *(bb2 + 1) = a22;
    }
    if (m - js == 1) {
        for (is = 0; is < js; is += 2) {
            a11 = *(aa1 + 0);
            a21 = *(aa1 + 1);
            aa1 += 2;
            // Introduce temporary to decouple read from immediate write — breaks RAW
            float t11 = a11, t21 = a21;
            *(bb1 + 0) = t11;
            *(bb1 + 1) = t21;
            *(cc1 + 0) = t11;
            *(cc2 + 0) = t21;
            bb1 += 2;
            cc1 += 2 * m;
            cc2 += 2 * m;
        }
        a11 = *(aa1 + 0);
        *(bb1 + 0) = a11;
    }
}
}
