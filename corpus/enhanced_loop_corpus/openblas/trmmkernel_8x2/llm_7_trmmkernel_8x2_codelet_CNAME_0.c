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
extern float a0;
extern float a1;
extern float b0;
extern float b1;
extern BLASLONG off;
extern BLASLONG temp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (j = 0; j < bn / 2; j += 1) {
    C0 = C;
    C1 = C0 + ldc;
    ptrba = ba;
    // Eliminate loop-carried dependencies by unrolling accumulation into separate accumulators
    for (i = 0; i < bm / 8; i += 1) {
        ptrbb = bb;
        // Initialize accumulator pairs independently to break false dependencies
        float r0_0 = 0, r0_1 = 0, r0_2 = 0, r0_3 = 0, r0_4 = 0, r0_5 = 0, r0_6 = 0, r0_7 = 0;
        float r1_0 = 0, r1_1 = 0, r1_2 = 0, r1_3 = 0, r1_4 = 0, r1_5 = 0, r1_6 = 0, r1_7 = 0;
        temp = off + 2;
        for (k = 0; k < temp; k++) {
            float local_b0 = ptrbb[0];
            float local_b1 = ptrbb[1];
            // Load all 'a' values first to reorder operations and reduce WAR hazards
            float a_vals[8];
            for (int idx = 0; idx < 8; idx++) {
                a_vals[idx] = ptrba[idx];
            }
            ptrba += 8;
            // Perform multiply-accumulate using local registers to remove WAW on 'a0/a1'
            r0_0 += a_vals[0] * local_b0;
            r1_0 += a_vals[0] * local_b1;
            r0_1 += a_vals[1] * local_b0;
            r1_1 += a_vals[1] * local_b1;
            r0_2 += a_vals[2] * local_b0;
            r1_2 += a_vals[2] * local_b1;
            r0_3 += a_vals[3] * local_b0;
            r1_3 += a_vals[3] * local_b1;
            r0_4 += a_vals[4] * local_b0;
            r1_4 += a_vals[4] * local_b1;
            r0_5 += a_vals[5] * local_b0;
            r1_5 += a_vals[5] * local_b1;
            r0_6 += a_vals[6] * local_b0;
            r1_6 += a_vals[6] * local_b1;
            r0_7 += a_vals[7] * local_b0;
            r1_7 += a_vals[7] * local_b1;
            ptrbb += 2;
        }
        // Reintroduce alpha scaling without modifying original variables until final store
        r0_0 *= alpha;
        r0_1 *= alpha;
        r0_2 *= alpha;
        r0_3 *= alpha;
        r0_4 *= alpha;
        r0_5 *= alpha;
        r0_6 *= alpha;
        r0_7 *= alpha;
        r1_0 *= alpha;
        r1_1 *= alpha;
        r1_2 *= alpha;
        r1_3 *= alpha;
        r1_4 *= alpha;
        r1_5 *= alpha;
        r1_6 *= alpha;
        r1_7 *= alpha;
        // Final non-overlapping store to eliminate partial WAW with next block
        C0[0] = r0_0; C0[1] = r0_1; C0[2] = r0_2; C0[3] = r0_3;
        C0[4] = r0_4; C0[5] = r0_5; C0[6] = r0_6; C0[7] = r0_7;
        C1[0] = r1_0; C1[1] = r1_1; C1[2] = r1_2; C1[3] = r1_3;
        C1[4] = r1_4; C1[5] = r1_5; C1[6] = r1_6; C1[7] = r1_7;
        temp = bk - off;
        temp -= 2;
        ptrba += temp * 8;
        ptrbb += temp * 2;
        C0 += 8;
        C1 += 8;
    }
    if (bm & 4) {
        ptrbb = bb;
        float r0_0 = 0, r0_1 = 0, r0_2 = 0, r0_3 = 0;
        float r1_0 = 0, r1_1 = 0, r1_2 = 0, r1_3 = 0;
        temp = off + 2;
        for (k = 0; k < temp; k++) {
            float lb0 = ptrbb[0], lb1 = ptrbb[1];
            float la0 = ptrba[0], la1 = ptrba[1], la2 = ptrba[2], la3 = ptrba[3];
            ptrba += 4;
            ptrbb += 2;
            r0_0 += la0 * lb0; r1_0 += la0 * lb1;
            r0_1 += la1 * lb0; r1_1 += la1 * lb1;
            r0_2 += la2 * lb0; r1_2 += la2 * lb1;
            r0_3 += la3 * lb0; r1_3 += la3 * lb1;
        }
        C0[0] = r0_0 * alpha; C0[1] = r0_1 * alpha;
        C0[2] = r0_2 * alpha; C0[3] = r0_3 * alpha;
        C1[0] = r1_0 * alpha; C1[1] = r1_1 * alpha;
        C1[2] = r1_2 * alpha; C1[3] = r1_3 * alpha;
        temp = bk - off;
        temp -= 2;
        ptrba += temp * 4;
        ptrbb += temp * 2;
        C0 += 4;
        C1 += 4;
    }
    if (bm & 2) {
        ptrbb = bb;
        float r0_0 = 0, r0_1 = 0, r1_0 = 0, r1_1 = 0;
        temp = off + 2;
        for (k = 0; k < temp; k++) {
            float lb0 = ptrbb[0], lb1 = ptrbb[1];
            float la0 = ptrba[0], la1 = ptrba[1];
            ptrba += 2;
            ptrbb += 2;
            r0_0 += la0 * lb0; r1_0 += la0 * lb1;
            r0_1 += la1 * lb0; r1_1 += la1 * lb1;
        }
        C0[0] = r0_0 * alpha; C0[1] = r0_1 * alpha;
        C1[0] = r1_0 * alpha; C1[1] = r1_1 * alpha;
        temp = bk - off;
        temp -= 2;
        ptrba += temp * 2;
        ptrbb += temp * 2;
        C0 += 2;
        C1 += 2;
    }
    if (bm & 1) {
        ptrbb = bb;
        float r0_0 = 0, r1_0 = 0;
        temp = off + 2;
        for (k = 0; k < temp; k++) {
            float lb0 = ptrbb[0], lb1 = ptrbb[1];
            float la0 = ptrba[0];
            ptrba++;
            ptrbb += 2;
            r0_0 += la0 * lb0;
            r1_0 += la0 * lb1;
        }
        C0[0] = r0_0 * alpha;
        C1[0] = r1_0 * alpha;
        temp = bk - off;
        temp -= 2;
        ptrba += temp;
        ptrbb += temp * 2;
        C0++;
        C1++;
    }
    k = (bk << 1);
    bb += k;
    C += (ldc << 1);
}
}
