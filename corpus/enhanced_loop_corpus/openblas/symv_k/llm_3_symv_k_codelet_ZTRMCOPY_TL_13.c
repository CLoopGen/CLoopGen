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



void loop() {
    for (js = 0; js < m; js += 2) {
        // Change access pattern to use strided access via pointer arithmetic with fixed increments
        aa1 = a;
        aa2 = a + lda;
        a += 2 * lda + 4;

        bb1 = b1;
        bb2 = b1 + 2 * m;
        b1 += 4 * m + 4;

        cc1 = b2;
        cc2 = b2 + 2 * m;
        b2 += 4 * m + 4;

        if (m - js >= 2) {
            // First block: direct and strided loads/stores using explicit offsets
            a11 = aa1[0]; a21 = aa1[1]; a31 = aa1[2]; a41 = aa1[3];
            a12 = aa2[2]; a22 = aa2[3];

            // Write to bb1 and bb2 with unit stride
            for (BLASLONG i = 0; i < 4; ++i) {
                bb1[i] = ((float*)&a11)[i];  // Pack a11-a41 into contiguous output
                bb2[i] = i < 2 ? ((float*)&a31)[i] : (i == 2 ? a12 : a22);
            }

            aa1 += 4; aa2 += 4;
            bb1 += 4; bb2 += 4;

            BLASLONG inner_iters = (m - js - 2) >> 1;
            for (BLASLONG i = 0; i < inner_iters; ++i) {
                // Load two vectors with regular strides
                a11 = *(aa1 + 0); a21 = *(aa1 + 1); a31 = *(aa1 + 2); a41 = *(aa1 + 3);
                a12 = *(aa2 + 0); a22 = *(aa2 + 1); a32 = *(aa2 + 2); a42 = *(aa2 + 3);

                // Store results with unit stride in bb1, bb2
                for (BLASLONG j = 0; j < 4; ++j) {
                    bb1[j] = ((float*)&a11)[j];
                    bb2[j] = ((float*)&a12)[j];
                }

                // Update cc1 and cc2 with column-major style strided updates
                for (BLASLONG j = 0; j < 2; ++j) {
                    cc1[j + 0] = ((float*)&a11)[j];
                    cc1[j + 2] = ((float*)&a12)[j];
                    cc2[j + 0] = ((float*)&a31)[j];
                    cc2[j + 2] = ((float*)&a32)[j];
                }

                aa1 += 4; aa2 += 4;
                bb1 += 4; bb2 += 4;
                cc1 += 4 * m; cc2 += 4 * m;
            }

            if (m & 1) {
                a11 = aa1[0]; a21 = aa1[1];
                a12 = aa2[0]; a22 = aa2[1];

                bb1[0] = a11; bb1[1] = a21;
                bb2[0] = a12; bb2[1] = a22;

                cc1[0] = a11; cc1[1] = a21;
                cc1[2] = a12; cc1[3] = a22;
            }
        }

        if (m - js == 1) {
            a11 = aa1[0]; a21 = aa1[1];
            bb1[0] = a11; bb1[1] = a21;
        }
    }
}
