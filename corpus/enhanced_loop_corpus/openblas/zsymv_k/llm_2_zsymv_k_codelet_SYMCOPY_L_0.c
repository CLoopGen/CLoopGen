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

        // Unrolled for-loop simulating strided access converted to unit stride via pointer arrays
        BLASLONG remaining = (m - js - 2);
        float *temp_aa1_stack[64], *temp_aa2_stack[64];
        float *temp_bb1_stack[64], *temp_bb2_stack[64];
        float *temp_cc1_stack[64], *temp_cc2_stack[64];

        BLASLONG idx = 0;
        for (; idx < remaining && idx < 64; ++idx) {
            temp_aa1_stack[idx] = aa1;
            temp_aa2_stack[idx] = aa2;
            temp_bb1_stack[idx] = bb1;
            temp_bb2_stack[idx] = bb2;
            temp_cc1_stack[idx] = cc1;
            temp_cc2_stack[idx] = cc2;

            aa1 += 2;
            aa2 += 2;
            bb1 += 2;
            bb2 += 2;
            cc1 += 2 * m;
            cc2 += 2 * m;
        }

        for (BLASLONG k = 0; k < idx; ++k) {
            a11 = temp_aa1_stack[k][0];
            a21 = temp_aa1_stack[k][1];
            a12 = temp_aa2_stack[k][0];
            a22 = temp_aa2_stack[k][1];

            temp_bb1_stack[k][0] = a11;
            temp_bb1_stack[k][1] = a21;
            temp_bb2_stack[k][0] = a12;
            temp_bb2_stack[k][1] = a22;

            temp_cc1_stack[k][0] = a11;
            temp_cc1_stack[k][1] = a12;
            temp_cc2_stack[k][0] = a21;
            temp_cc2_stack[k][1] = a22;
        }

        if (remaining > 64) {
            // Handle overflow with direct access (not unrolled)
            aa1 = a - 2 * lda - 2 + (2 + 64*2); // approximate recovery
            bb1 = b1 - 2 * m - 2 + (2 + 64*2);
            cc1 = b2 - 2 * m - 2 + (2 + 64*2 * m);
            for (BLASLONG i = 64; i < remaining; ++i) {
                a11 = *(aa1 + 0);
                a21 = *(aa1 + 1);
                a12 = *(aa2 + 0);
                a22 = *(aa2 + 1);

                *(bb1 + 0) = a11;
                *(bb1 + 1) = a21;
                *(bb2 + 0) = a12;
                *(bb2 + 1) = a22;

                *(cc1 + 0) = a11;
                *(cc1 + 1) = a12;
                *(cc2 + 0) = a21;
                *(cc2 + 1) = a22;

                aa1 += 2;
                aa2 += 2;
                bb1 += 2;
                bb2 += 2;
                cc1 += 2 * m;
                cc2 += 2 * m;
            }
        }

        // Final odd element
        if ((m - js - 2) & 1) {
            a11 = *(aa1 + 0);
            a12 = *(aa2 + 0);
            *(bb1 + 0) = a11;
            *(bb2 + 0) = a12;
            *(cc1 + 0) = a11;
            *(cc1 + 1) = a12;
        }
    }

    if (m - js == 1) {
        a11 = *(aa1 + 0);
        *(bb1 + 0) = a11;
    }
}
}
