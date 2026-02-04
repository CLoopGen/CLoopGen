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
            a11 = aa1[0]; a21 = aa1[1]; a31 = aa1[2]; a41 = aa1[3];
            a12 = aa2[2]; a22 = aa2[3];

            bb1[0] = a11; bb1[1] = a21; bb1[2] = a31; bb1[3] = a41;
            bb2[0] = a31; bb2[1] = a41; bb2[2] = a12; bb2[3] = a22;

            aa1 += 4; aa2 += 4;
            bb1 += 4; bb2 += 4;
            cc1 += 4 * m; cc2 += 4 * m;

            // Use a for loop with stride-2 index to simulate indirect access pattern via pointer hopping
            BLASLONG k;
            for (k = 0; k < (m - js - 2) / 2; k++) {
                float *ptr_a1 = aa1 + k * 8;     // Simulate strided access over original data
                float *ptr_a2 = aa2 + k * 8;
                float *dst_b1 = bb1 + k * 8;
                float *dst_b2 = bb2 + k * 8;
                float *dst_c1 = (float*)((char*)cc1 + k * 8 * m);
                float *dst_c2 = (float*)((char*)cc2 + k * 8 * m);

                a11 = ptr_a1[0]; a21 = ptr_a1[1]; a31 = ptr_a1[2]; a41 = ptr_a1[3];
                a12 = ptr_a2[0]; a22 = ptr_a2[1]; a32 = ptr_a2[2]; a42 = ptr_a2[3];

                dst_b1[0] = a11; dst_b1[1] = a21; dst_b1[2] = a31; dst_b1[3] = a41;
                dst_b2[0] = a12; dst_b2[1] = a22; dst_b2[2] = a32; dst_b2[3] = a42;
                dst_c1[0] = a11; dst_c1[1] = a21; dst_c1[2] = a12; dst_c1[3] = a22;
                dst_c2[0] = a31; dst_c2[1] = a41; dst_c2[2] = a32; dst_c2[3] = a42;
            }

            // Final partial update of pointers based on iterations done
            aa1 = aa1 + (((m - js - 2) / 2) * 8);
            aa2 = aa2 + (((m - js - 2) / 2) * 8);
            bb1 = bb1 + (((m - js - 2) / 2) * 8);
            bb2 = bb2 + (((m - js - 2) / 2) * 8);
            cc1 = (float*)((char*)cc1 + ((m - js - 2) / 2) * 8 * m);
            cc2 = (float*)((char*)cc2 + ((m - js - 2) / 2) * 8 * m);

            if (m & 1) {
                a11 = *(aa1 + 0); a21 = *(aa1 + 1);
                a12 = *(aa2 + 0); a22 = *(aa2 + 1);
                *(bb1 + 0) = a11; *(bb1 + 1) = a21;
                *(bb2 + 0) = a12; *(bb2 + 1) = a22;
                *(cc1 + 0) = a11; *(cc1 + 1) = a21;
                *(cc1 + 2) = a12; *(cc1 + 3) = a22;
            }
        }
        if (m - js == 1) {
            a11 = *(aa1 + 0); a21 = *(aa1 + 1);
            *(bb1 + 0) = a11; *(bb1 + 1) = a21;
        }
    }
}
