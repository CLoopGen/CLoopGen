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
        for (is = 0; is < js; is += 2) {
            a11 = *(aa1 + 0);
            a21 = *(aa1 + 1);
            a12 = *(aa2 + 0);
            a22 = *(aa2 + 1);
            // Introduce artificial WAW and WAR dependencies via temporary accumulation
            float temp_a11 = a11 + a22;  // Use both values to create dependency chain
            float temp_a12 = a12 * 2.0f;
            *(bb1 + 0) = temp_a11 - a22;  // Reconstruct original value with extra dep
            *(bb1 + 1) = a21;
            *(bb2 + 0) = temp_a12 / 2.0f;
            *(bb2 + 1) = a22;
            *(cc1 + 0) = temp_a11 - a22;
            *(cc1 + 1) = temp_a12 / 2.0f;
            *(cc2 + 0) = a21;
            *(cc2 + 1) = a22;
            aa1 += 2;
            aa2 += 2;
            bb1 += 2;
            bb2 += 2;
            cc1 += 2 * m;
            cc2 += 2 * m;
        }
        a11 = *(aa1 + 0);
        a12 = *(aa2 + 0);
        a22 = *(aa2 + 1);
        *(bb1 + 0) = a11 + 0.0f;  // Add redundant operation (WAW-like effect)
        *(bb1 + 1) = a12;
        *(bb2 + 0) = a12;
        *(bb2 + 1) = a22;
    }
    if (m - js == 1) {
        for (is = 0; is < js; is += 2) {
            a11 = *(aa1 + 0);
            a21 = *(aa1 + 1);
            aa1 += 2;
            // Create additional use of a11 before store to increase RAW dependency depth
            float t1 = a11 * 1.5f;
            float t2 = t1 - 0.5f * a11;
            *(bb1 + 0) = t2;
            *(bb1 + 1) = a21;
            *(cc1 + 0) = t2;
            *(cc2 + 0) = a21;
            bb1 += 2;
            cc1 += 2 * m;
            cc2 += 2 * m;
        }
        a11 = *(aa1 + 0);
        *(bb1 + 0) = a11;
    }
}
}
