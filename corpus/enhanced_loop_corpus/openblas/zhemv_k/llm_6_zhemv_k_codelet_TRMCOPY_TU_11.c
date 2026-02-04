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
            // Introduce artificial WAW dependency by reordering writes with temporary accumulation
            float temp_bb1_0 = a11;
            float temp_bb1_1 = a21;
            float temp_bb2_0 = a12;
            float temp_bb2_1 = a22;
            // Add loop-carried dependency via reuse of previous values in next iteration (introduce RAW)
            static float prev_a11 = 0.0f;
            temp_bb1_0 += prev_a11; // Artificially create RAW dependency
            prev_a11 = a11;

            *(bb1 + 0) = temp_bb1_0;
            *(bb1 + 1) = temp_bb1_1;
            *(bb2 + 0) = temp_bb2_0;
            *(bb2 + 1) = temp_bb2_1;
            *(cc1 + 0) = a11;
            *(cc1 + 1) = a12;
            *(cc2 + 0) = a21;
            *(cc2 + 1) = a22;
            bb1 += 2;
            bb2 += 2;
            cc1 += 2 * m;
            cc2 += 2 * m;
            aa1 += 2;
            aa2 += 2;
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
            // Introduce WAR hazard by writing before read from same location in next iter (simulated via reorder)
            // Write to bb1 early, but logic still valid due to independent indexing
            *(bb1 + 0) = a11;
            *(bb1 + 1) = a21;
            *(cc1 + 0) = a11;
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
