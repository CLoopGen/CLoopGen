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
    // Use strided access via index scaling instead of pointer arithmetic
    BLASLONG idx_a1 = 0 * lda;
    BLASLONG idx_a2 = 1 * lda;
    BLASLONG idx_b1 = 0;
    BLASLONG idx_b2 = 2 * m;
    BLASLONG idx_c1 = 0;
    BLASLONG idx_c2 = 2 * m;

    a += 2 * lda;
    b1 += 4 * m;
    b2 += 4;

    if (m - js >= 2) {
        for (is = 0; is < js; is += 2) {
            // Strided memory access using scaled indices
            a11 = a[idx_a1 + 0]; a21 = a[idx_a1 + 1];
            a31 = a[idx_a1 + 2]; a41 = a[idx_a1 + 3];
            a12 = a[idx_a2 + 0]; a22 = a[idx_a2 + 1];
            a32 = a[idx_a2 + 2]; a42 = a[idx_a2 + 3];

            idx_a1 += 4;
            idx_a2 += 4;

            b1[idx_b1 + 0] = a11;      b1[idx_b1 + 1] = -a21;
            b1[idx_b1 + 2] = a31;      b1[idx_b1 + 3] = -a41;
            b1[idx_b2 + 0] = a12;      b1[idx_b2 + 1] = -a22;
            b1[idx_b2 + 2] = a32;      b1[idx_b2 + 3] = -a42;

            b2[idx_c1 + 0] = a11;      b2[idx_c1 + 1] = a21;
            b2[idx_c1 + 2] = a12;      b2[idx_c1 + 3] = a22;
            b2[idx_c2 + 0] = a31;      b2[idx_c2 + 1] = a41;
            b2[idx_c2 + 2] = a32;      b2[idx_c2 + 3] = a42;

            idx_b1 += 4;
            idx_b2 += 4;
            idx_c1 += 4 * m;
            idx_c2 += 4 * m;
        }
        a11 = a[idx_a1 + 0];
        a12 = a[idx_a2 + 0];
        a22 = a[idx_a2 + 1];
        a32 = a[idx_a2 + 2];
        b1[idx_b1 + 0] = a11;
        b1[idx_b1 + 1] = 0.;
        b1[idx_b1 + 2] = a12;
        b1[idx_b1 + 3] = a22;
        b1[idx_b2 + 0] = a12;
        b1[idx_b2 + 1] = -a22;
        b1[idx_b2 + 2] = a32;
        b1[idx_b2 + 3] = 0.;
    }
    if (m - js == 1) {
        for (is = 0; is < js; is += 2) {
            a11 = a[idx_a1 + 0]; a21 = a[idx_a1 + 1];
            a31 = a[idx_a1 + 2]; a41 = a[idx_a1 + 3];

            idx_a1 += 4;

            b1[idx_b1 + 0] = a11;      b1[idx_b1 + 1] = -a21;
            b1[idx_b1 + 2] = a31;      b1[idx_b1 + 3] = -a41;

            b2[idx_c1 + 0] = a11;      b2[idx_c1 + 1] = a21;
            b2[idx_c2 + 0] = a31;      b2[idx_c2 + 1] = a41;

            idx_b1 += 4;
            idx_c1 += 4 * m;
            idx_c2 += 4 * m;
        }
        a11 = a[idx_a1 + 0];
        b1[idx_b1 + 0] = a11;
        b1[idx_b1 + 1] = 0.;
    }
}
}
