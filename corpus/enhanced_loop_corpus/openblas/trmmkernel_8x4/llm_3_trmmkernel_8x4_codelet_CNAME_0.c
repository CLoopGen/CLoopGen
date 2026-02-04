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
extern float res1_0;
extern float res1_1;
extern float res1_2;
extern float res1_3;
extern float res1_4;
extern float res1_5;
extern float res1_6;
extern float res1_7;
extern float res2_0;
extern float res2_1;
extern float res2_2;
extern float res2_3;
extern float res2_4;
extern float res2_5;
extern float res2_6;
extern float res2_7;
extern float res3_0;
extern float res3_1;
extern float res3_2;
extern float res3_3;
extern float res3_4;
extern float res3_5;
extern float res3_6;
extern float res3_7;
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
    C2 = C1 + ldc;
    C3 = C2 + ldc;
    ptrba = ba;
    for (i = 0; i < bm / 8; i += 1) {
        ptrbb = bb;
        // Accumulate into local array using indirect indexing via offsets
        float r0[8] = {0}, r1[8] = {0}, r2[8] = {0}, r3[8] = {0};
        temp = off + 4;
        for (k = 0; k < temp; k++) {
            // Load B values once per iteration
            float bvec[4];
            bvec[0] = ptrbb[0]; bvec[1] = ptrbb[1]; bvec[2] = ptrbb[2]; bvec[3] = ptrbb[3];

            // Use indirect indexing through a stride table for A
            int idx = 0;
            for (int s = 0; s < 8; s++, idx++) {
                float a_val = ptrba[idx];
                r0[s] += a_val * bvec[0];
                r1[s] += a_val * bvec[1];
                r2[s] += a_val * bvec[2];
                r3[s] += a_val * bvec[3];
            }
            ptrba += 8;
            ptrbb += 4;
        }
        // Scale and store with indirect write
        for (int s = 0; s < 8; s++) {
            r0[s] *= alpha; r1[s] *= alpha; r2[s] *= alpha; r3[s] *= alpha;
            C0[s] = r0[s]; C1[s] = r1[s]; C2[s] = r2[s]; C3[s] = r3[s];
        }

        temp = bk - off - 4;
        ptrba += temp * 8;
        ptrbb += temp * 4;
        C0 += 8; C1 += 8; C2 += 8; C3 += 8;
    }
    if (bm & 4) {
        ptrbb = bb;
        float r0[4] = {0}, r1[4] = {0}, r2[4] = {0}, r3[4] = {0};
        temp = off + 4;
        for (k = 0; k < temp; k++) {
            float bvec[4];
            bvec[0] = ptrbb[0]; bvec[1] = ptrbb[1]; bvec[2] = ptrbb[2]; bvec[3] = ptrbb[3];
            for (int s = 0; s < 4; s++) {
                float a_val = ptrba[s];
                r0[s] += a_val * bvec[0];
                r1[s] += a_val * bvec[1];
                r2[s] += a_val * bvec[2];
                r3[s] += a_val * bvec[3];
            }
            ptrba += 4;
            ptrbb += 4;
        }
        for (int s = 0; s < 4; s++) {
            r0[s] *= alpha; r1[s] *= alpha; r2[s] *= alpha; r3[s] *= alpha;
            C0[s] = r0[s]; C1[s] = r1[s]; C2[s] = r2[s]; C3[s] = r3[s];
        }
        temp = bk - off - 4;
        ptrba += temp * 4;
        ptrbb += temp * 4;
        C0 += 4; C1 += 4; C2 += 4; C3 += 4;
    }
    if (bm & 2) {
        ptrbb = bb;
        float r0[2] = {0}, r1[2] = {0}, r2[2] = {0}, r3[2] = {0};
        temp = off + 4;
        for (k = 0; k < temp; k++) {
            b0 = ptrbb[0]; b1 = ptrbb[1]; b2 = ptrbb[2]; b3 = ptrbb[3];
            a0 = ptrba[0]; a1 = ptrba[1];
            r0[0] += a0 * b0; r1[0] += a0 * b1; r2[0] += a0 * b2; r3[0] += a0 * b3;
            r0[1] += a1 * b0; r1[1] += a1 * b1; r2[1] += a1 * b2; r3[1] += a1 * b3;
            ptrba += 2;
            ptrbb += 4;
        }
        r0[0] *= alpha; r0[1] *= alpha;
        r1[0] *= alpha; r1[1] *= alpha;
        r2[0] *= alpha; r2[1] *= alpha;
        r3[0] *= alpha; r3[1] *= alpha;
        C0[0] = r0[0]; C0[1] = r0[1];
        C1[0] = r1[0]; C1[1] = r1[1];
        C2[0] = r2[0]; C2[1] = r2[1];
        C3[0] = r3[0]; C3[1] = r3[1];
        temp = bk - off - 4;
        ptrba += temp * 2;
        ptrbb += temp * 4;
        C0 += 2; C1 += 2; C2 += 2; C3 += 2;
    }
    if (bm & 1) {
        ptrbb = bb;
        float r0 = 0, r1 = 0, r2 = 0, r3 = 0;
        temp = off + 4;
        for (k = 0; k < temp; k++) {
            b0 = ptrbb[0]; b1 = ptrbb[1]; b2 = ptrbb[2]; b3 = ptrbb[3];
            a0 = ptrba[0];
            r0 += a0 * b0; r1 += a0 * b1; r2 += a0 * b2; r3 += a0 * b3;
            ptrba++;
            ptrbb += 4;
        }
        C0[0] = r0 * alpha;
        C1[0] = r1 * alpha;
        C2[0] = r2 * alpha;
        C3[0] = r3 * alpha;
        temp = bk - off - 4;
        ptrba += temp;
        ptrbb += temp * 4;
        C0++; C1++; C2++; C3++;
    }
    bb += (bk << 2);
    C += (ldc << 2);
}
}
