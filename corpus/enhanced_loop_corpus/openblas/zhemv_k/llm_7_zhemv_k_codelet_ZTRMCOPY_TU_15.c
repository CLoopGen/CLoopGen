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
    a += 2 * lda;
    bb1 = b1 + 0 * m;
    bb2 = b1 + 2 * m;
    b1 += 4 * m;
    cc1 = b2 + 0 * m;
    cc2 = b2 + 2 * m;
    b2 += 4;
    if (m - js >= 2) {
        // Eliminate loop-carried dependency by unrolling assumption and using local accumulators
        float local_bb[8], local_cc[8];
        for (is = 0; is < js; is += 2) {
            a11 = *(aa1 + 0);
            a21 = *(aa1 + 1);
            a31 = *(aa1 + 2);
            a41 = *(aa1 + 3);
            a12 = *(aa2 + 0);
            a22 = *(aa2 + 1);
            a32 = *(aa2 + 2);
            a42 = *(aa2 + 3);
            aa1 += 4;
            aa2 += 4;

            // Store into local array first — break RAW/WAR dependencies with memory
            local_bb[0] = a11;
            local_bb[1] = a21;
            local_bb[2] = a31;
            local_bb[3] = a41;
            local_bb[4] = a12;
            local_bb[5] = a22;
            local_bb[6] = a32;
            local_bb[7] = a42;

            local_cc[0] = a11;
            local_cc[1] = a21;
            local_cc[2] = a12;
            local_cc[3] = a22;
            local_cc[4] = a31;
            local_cc[5] = a41;
            local_cc[6] = a32;
            local_cc[7] = a42;

            // Now flush local values to memory — removes intra-loop memory dependency
            for (int k = 0; k < 8; ++k) {
                if (k < 4) *(bb1 + k) = local_bb[k];
                if (k < 4) *(bb2 + k) = local_bb[k+4];
                if (k < 4) *(cc1 + k * m) = local_cc[k];
                if (k < 4) *(cc2 + k * m) = local_cc[k+4];
            }

            bb1 += 4;
            bb2 += 4;
            cc1 += 4 * m;
            cc2 += 4 * m;
        }
        // Final block updated with direct access but preserve semantics
        a11 = *(aa1 + 0);
        a21 = *(aa1 + 1);
        a12 = *(aa2 + 0);
        a22 = *(aa2 + 1);
        a32 = *(aa2 + 2);
        a42 = *(aa2 + 3);
        *(bb1 + 0) = a11;
        *(bb1 + 1) = a21;
        *(bb1 + 2) = a12;
        *(bb1 + 3) = a22;
        *(bb2 + 0) = a12;
        *(bb2 + 1) = a22;
        *(bb2 + 2) = a32;
        *(bb2 + 3) = a42;
    }
    if (m - js == 1) {
        for (is = 0; is < js; is += 2) {
            a11 = *(aa1 + 0);
            a21 = *(aa1 + 1);
            a31 = *(aa1 + 2);
            a41 = *(aa1 + 3);
            aa1 += 4;
            // Reduce memory writes by batching
            float temp_b[4] = {a11, a21, a31, a41};
            float temp_c1[2] = {a11, a21};
            float temp_c2[2] = {a31, a41};
            for (int i = 0; i < 4; ++i) *(bb1 + i) = temp_b[i];
            for (int i = 0; i < 2; ++i) {
                *(cc1 + i * m) = temp_c1[i];
                *(cc2 + i * m) = temp_c2[i];
            }
            bb1 += 4;
            cc1 += 4 * m;
            cc2 += 4 * m;
        }
        a11 = *(aa1 + 0);
        a21 = *(aa1 + 1);
        *(bb1 + 0) = a11;
        *(bb1 + 1) = a21;
    }
}
}
