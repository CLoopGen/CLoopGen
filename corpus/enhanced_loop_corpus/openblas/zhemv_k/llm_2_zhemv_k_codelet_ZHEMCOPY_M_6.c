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
    a += 2 * lda + 4;
    bb1 = b1 + 0 * m;
    bb2 = b1 + 2 * m;
    b1 += 4 * m + 4;
    cc1 = b2 + 0 * m;
    cc2 = b2 + 2 * m;
    b2 += 4 * m + 4;

    if (m - js >= 2) {
        // Unroll first iteration with consecutive memory writes using array indexing
        *(bb1 + 0) = *(aa1 + 0);
        *(bb1 + 1) = 0.0f;
        *(bb1 + 2) = *(aa1 + 2);
        *(bb1 + 3) = -(*(aa1 + 3));
        *(bb2 + 0) = *(aa1 + 2);
        *(bb2 + 1) = *(aa1 + 3);
        *(bb2 + 2) = *(aa2 + 2);
        *(bb2 + 3) = 0.0f;

        // Update pointers once before loop to enable unit-stride access
        aa1 += 4;
        aa2 += 4;
        bb1 += 4;
        bb2 += 4;
        cc1 += 4 * m;
        cc2 += 4 * m;

        BLASLONG remaining = (m - js - 2) >> 1;
        for (BLASLONG k = 0; k < remaining; k++) {
            float vals_a[8] = {
                *(aa1 + 0), *(aa1 + 1), *(aa1 + 2), *(aa1 + 3),
                *(aa2 + 0), *(aa2 + 1), *(aa2 + 2), *(aa2 + 3)
            };

            // Write to B arrays with unit stride
            bb1[0] = vals_a[0]; bb1[1] = -vals_a[1]; bb1[2] = vals_a[2]; bb1[3] = -vals_a[3];
            bb2[0] = vals_a[4]; bb2[1] = -vals_a[5]; bb2[2] = vals_a[6]; bb2[3] = -vals_a[7];

            // Write to C arrays with indirect but predictable access
            cc1[0] = vals_a[0]; cc1[1] = vals_a[1]; cc1[2] = vals_a[4]; cc1[3] = vals_a[5];
            cc2[0] = vals_a[2]; cc2[1] = vals_a[3]; cc2[2] = vals_a[6]; cc2[3] = vals_a[7];

            // Advance all pointers by fixed strides
            aa1 += 4;
            aa2 += 4;
            bb1 += 4;
            bb2 += 4;
            cc1 += 4 * m;
            cc2 += 4 * m;
        }

        if (m & 1) {
            *(bb1 + 0) = *(aa1 + 0);
            *(bb1 + 1) = -(*(aa1 + 1));
            *(bb2 + 0) = *(aa2 + 0);
            *(bb2 + 1) = -(*(aa2 + 1));
            *(cc1 + 0) = *(aa1 + 0); *(cc1 + 1) = *(aa1 + 1);
            *(cc1 + 2) = *(aa2 + 0); *(cc1 + 3) = *(aa2 + 1);
        }
    }

    if (m - js == 1) {
        *(bb1 + 0) = *(aa1 + 0);
        *(bb1 + 1) = 0.0f;
    }
}
}
