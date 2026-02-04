#include <stdio.h>

typedef long BLASLONG;

extern BLASLONG bm;
extern BLASLONG bn;
extern BLASLONG bk;
extern float alpha;
extern float *ba;
extern float *bb;
extern float *C;
extern BLASLONG ldc;
extern BLASLONG i;
extern BLASLONG j;
extern BLASLONG k;
extern float *C0;
extern float *C1;
extern float *C2;
extern float *C3;
extern float *ptrba;
extern float *ptrbb;
extern float res0_0;
extern float res0_1;
extern float res0_2;
extern float res0_3;
extern float res0_4;
extern float res0_5;
extern float res0_6;
extern float res0_7;
extern float res0_8;
extern float res0_9;
extern float res0_10;
extern float res0_11;
extern float res0_12;
extern float res0_13;
extern float res0_14;
extern float res0_15;
extern float res1_0;
extern float res1_1;
extern float res1_2;
extern float res1_3;
extern float res1_4;
extern float res1_5;
extern float res1_6;
extern float res1_7;
extern float res1_8;
extern float res1_9;
extern float res1_10;
extern float res1_11;
extern float res1_12;
extern float res1_13;
extern float res1_14;
extern float res1_15;
extern float res2_0;
extern float res2_1;
extern float res2_2;
extern float res2_3;
extern float res2_4;
extern float res2_5;
extern float res2_6;
extern float res2_7;
extern float res2_8;
extern float res2_9;
extern float res2_10;
extern float res2_11;
extern float res2_12;
extern float res2_13;
extern float res2_14;
extern float res2_15;
extern float res3_0;
extern float res3_1;
extern float res3_2;
extern float res3_3;
extern float res3_4;
extern float res3_5;
extern float res3_6;
extern float res3_7;
extern float res3_8;
extern float res3_9;
extern float res3_10;
extern float res3_11;
extern float res3_12;
extern float res3_13;
extern float res3_14;
extern float res3_15;
extern float a0;
extern float a1;
extern float b0;
extern float b1;
extern float b2;
extern float b3;
extern BLASLONG off;
extern BLASLONG temp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (j = 0; j < bn / 4; j += 1) {
    C0 = C;
    C1 = C0 + ldc;
    C2 = C0 + 2 * ldc;
    C3 = C0 + 3 * ldc;
    ptrba = ba;

    // Eliminate loop-carried dependencies by unrolling accumulation into independent phases
    for (i = 0; i < bm / 16; i += 1) {
        ptrbb = bb;
        // Initialize accumulators with zero
        float acc0[16] = {0}, acc1[16] = {0}, acc2[16] = {0}, acc3[16] = {0};

        temp = off + 4;
        for (k = 0; k < temp; k++) {
            b0 = ptrbb[0]; b1 = ptrbb[1]; b2 = ptrbb[2]; b3 = ptrbb[3];
            // Load all 16 values upfront to remove address dependency chains
            float a[16];
            for (int m = 0; m < 16; m++) a[m] = ptrba[m];

            // Perform independent updates without intermediate dependencies
            #pragma GCC unroll 16
            for (int m = 0; m < 16; m += 2) {
                acc0[m]   += a[m] * b0;
                acc1[m]   += a[m] * b1;
                acc2[m]   += a[m] * b2;
                acc3[m]   += a[m] * b3;
                acc0[m+1] += a[m+1] * b0;
                acc1[m+1] += a[m+1] * b1;
                acc2[m+1] += a[m+1] * b2;
                acc3[m+1] += a[m+1] * b3;
            }

            ptrba += 16;
            ptrbb += 4;
        }

        // Finalize and scale results
        for (int m = 0; m < 16; m++) {
            acc0[m] *= alpha;
            acc1[m] *= alpha;
            acc2[m] *= alpha;
            acc3[m] *= alpha;
        }

        // Store results directly
        for (int m = 0; m < 16; m++) {
            C0[m] = acc0[m];
            C1[m] = acc1[m];
            C2[m] = acc2[m];
            C3[m] = acc3[m];
        }

        temp = bk - off - 4;
        ptrba += temp * 16;
        ptrbb += temp * 4;
        C0 += 16; C1 += 16; C2 += 16; C3 += 16;
    }

    if (bm & 8) {
        ptrbb = bb;
        float acc0[8] = {0}, acc1[8] = {0}, acc2[8] = {0}, acc3[8] = {0};
        temp = off + 4;
        for (k = 0; k < temp; k++) {
            b0 = ptrbb[0]; b1 = ptrbb[1]; b2 = ptrbb[2]; b3 = ptrbb[3];
            float a[8];
            for (int m = 0; m < 8; m++) a[m] = ptrba[m];

            #pragma GCC unroll 8
            for (int m = 0; m < 8; m++) {
                acc0[m] += a[m] * b0;
                acc1[m] += a[m] * b1;
                acc2[m] += a[m] * b2;
                acc3[m] += a[m] * b3;
            }

            ptrba += 8;
            ptrbb += 4;
        }

        for (int m = 0; m < 8; m++) {
            acc0[m] *= alpha;
            acc1[m] *= alpha;
            acc2[m] *= alpha;
            acc3[m] *= alpha;
        }

        for (int m = 0; m < 8; m++) {
            C0[m] = acc0[m];
            C1[m] = acc1[m];
            C2[m] = acc2[m];
            C3[m] = acc3[m];
        }

        temp = bk - off - 4;
        ptrba += temp * 8;
        ptrbb += temp * 4;
        C0 += 8; C1 += 8; C2 += 8; C3 += 8;
    }

    if (bm & 4) {
        ptrbb = bb;
        float acc0[4] = {0}, acc1[4] = {0}, acc2[4] = {0}, acc3[4] = {0};
        temp = off + 4;
        for (k = 0; k < temp; k++) {
            b0 = ptrbb[0]; b1 = ptrbb[1]; b2 = ptrbb[2]; b3 = ptrbb[3];
            float a[4] = {ptrba[0], ptrba[1], ptrba[2], ptrba[3]};

            acc0[0] += a[0] * b0; acc1[0] += a[0] * b1; acc2[0] += a[0] * b2; acc3[0] += a[0] * b3;
            acc0[1] += a[1] * b0; acc1[1] += a[1] * b1; acc2[1] += a[1] * b2; acc3[1] += a[1] * b3;
            acc0[2] += a[2] * b0; acc1[2] += a[2] * b1; acc2[2] += a[2] * b2; acc3[2] += a[2] * b3;
            acc0[3] += a[3] * b0; acc1[3] += a[3] * b1; acc2[3] += a[3] * b2; acc3[3] += a[3] * b3;

            ptrba += 4;
            ptrbb += 4;
        }

        for (int m = 0; m < 4; m++) {
            acc0[m] *= alpha;
            acc1[m] *= alpha;
            acc2[m] *= alpha;
            acc3[m] *= alpha;
        }

        for (int m = 0; m < 4; m++) {
            C0[m] = acc0[m];
            C1[m] = acc1[m];
            C2[m] = acc2[m];
            C3[m] = acc3[m];
        }

        temp = bk - off - 4;
        ptrba += temp * 4;
        ptrbb += temp * 4;
        C0 += 4; C1 += 4; C2 += 4; C3 += 4;
    }

    if (bm & 2) {
        ptrbb = bb;
        float acc0[2] = {0}, acc1[2] = {0}, acc2[2] = {0}, acc3[2] = {0};
        temp = off + 4;
        for (k = 0; k < temp; k++) {
            b0 = ptrbb[0]; b1 = ptrbb[1]; b2 = ptrbb[2]; b3 = ptrbb[3];
            acc0[0] += ptrba[0] * b0; acc1[0] += ptrba[0] * b1;
            acc2[0] += ptrba[0] * b2; acc3[0] += ptrba[0] * b3;
            acc0[1] += ptrba[1] * b0; acc1[1] += ptrba[1] * b1;
            acc2[1] += ptrba[1] * b2; acc3[1] += ptrba[1] * b3;

            ptrba += 2;
            ptrbb += 4;
        }

        acc0[0] *= alpha; acc0[1] *= alpha;
        acc1[0] *= alpha; acc1[1] *= alpha;
        acc2[0] *= alpha; acc2[1] *= alpha;
        acc3[0] *= alpha; acc3[1] *= alpha;

        C0[0] = acc0[0]; C0[1] = acc0[1];
        C1[0] = acc1[0]; C1[1] = acc1[1];
        C2[0] = acc2[0]; C2[1] = acc2[1];
        C3[0] = acc3[0]; C3[1] = acc3[1];

        temp = bk - off - 4;
        ptrba += temp * 2;
        ptrbb += temp * 4;
        C0 += 2; C1 += 2; C2 += 2; C3 += 2;
    }

    if (bm & 1) {
        ptrbb = bb;
        float acc0 = 0, acc1 = 0, acc2 = 0, acc3 = 0;
        temp = off + 4;
        for (k = 0; k < temp; k++) {
            b0 = ptrbb[0]; b1 = ptrbb[1]; b2 = ptrbb[2]; b3 = ptrbb[3];
            float a0 = ptrba[0];
            acc0 += a0 * b0;
            acc1 += a0 * b1;
            acc2 += a0 * b2;
            acc3 += a0 * b3;

            ptrba += 1;
            ptrbb += 4;
        }

        acc0 *= alpha; acc1 *= alpha; acc2 *= alpha; acc3 *= alpha;
        C0[0] = acc0; C1[0] = acc1; C2[0] = acc2; C3[0] = acc3;

        temp = bk - off - 4;
        ptrba += temp;
        ptrbb += temp * 4;
        C0 += 1; C1 += 1; C2 += 1; C3 += 1;
    }

    bb += (bk << 2);
    C += (ldc << 2);
}
}
