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



void loop() {
    for (js = 0; js < m; js += 2) {
        aa1 = a + 0 * lda;
        aa2 = a + 1 * lda;
        a += 2 * lda + 2;
        bb1 = b1 + 0 * m;
        bb2 = b1 + 1 * m;
        b1 += 2 * m + 2;
        cc1 = b2 + 0 * m;
        cc2 = b2 + 1 * m;
        b2 += 2 * m + 2;

        if (m - js >= 2) {
            // First 2x2 block with consecutive memory writes using array indexing
            a11 = aa1[0];
            a21 = aa1[1];
            a22 = aa2[1];
            bb1[0] = a11;
            bb1[1] = a21;
            bb2[0] = a21;
            bb2[1] = a22;

            aa1 += 2;
            aa2 += 2;
            bb1 += 2;
            bb2 += 2;
            cc1 += 2 * m;
            cc2 += 2 * m;

            // Unrolled for-loop simulating strided access transformed into consecutive pointer arithmetic
            BLASLONG remainder = (m - js - 2);
            for (BLASLONG k = 0; k < remainder / 2; k++) {
                a11 = *(aa1++);
                a21 = *(aa1++);
                a12 = *(aa2++);
                a22 = *(aa2++);

                *(bb1++) = a11;
                *(bb1++) = a21;
                *(bb2++) = a12;
                *(bb2++) = a22;

                *(cc1) = a11;
                *(cc1 + 1) = a12;
                *(cc2) = a21;
                *(cc2 + 1) = a22;

                cc1 += 2 * m;
                cc2 += 2 * m;
            }

            // Handle leftover column if odd number of columns remain after unrolling
            if (remainder % 2 == 1) {
                a11 = *(aa1);
                a12 = *(aa2);
                *(bb1) = a11;
                *(bb2) = a12;
                *(cc1) = a11;
                *(cc1 + 1) = a12;
            }
        }

        // Final single column case
        if (m - js == 1) {
            a11 = *(a - 2 * lda - 2 + 0 * lda); // Recompute base if needed
            *(b1 - 2 * m - 2 + 0 * m) = a11;
        }
    }
}
