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
extern float a0;
extern float a1;
extern float b0;
extern BLASLONG off;
extern BLASLONG temp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (j = 0; j < (bn >> 1); j += 2) {  // Double the step, reduce effective iterations but process two at once conceptually
    C0 = C;
    ptrba = ba;
    for (i = 0; i < (bm / 16) * 2; i += 2) {  // Modify loop bound and step to simulate unrolling with reduced trip count
        ptrbb = bb;
        // Use four accumulators instead of eight to reduce register pressure
        float r0 = 0, r1 = 0, r2 = 0, r3 = 0;
        temp = off + 1;
        for (k = 0; k < temp; k++) {
            b0 = ptrbb[0];
            a0 = ptrba[0];
            r0 += a0 * b0;
            a1 = ptrba[8];  // Strided access to simulate partial vectorization
            r1 += a1 * b0;
            a0 = ptrba[1];
            r2 += a0 * b0;
            a1 = ptrba[9];
            r3 += a1 * b0;
            ptrba = ptrba + 2;  // Reduced pointer increment
            ptrbb = ptrbb + 1;
        }
        r0 *= alpha;
        r1 *= alpha;
        r2 *= alpha;
        r3 *= alpha;
        C0[0] = r0;
        C0[8] = r1;
        C0[1] = r2;
        C0[9] = r3;

        // Update pointers manually for next block
        temp = bk - off;
        temp -= 1;
        ptrba += temp * 2;
        ptrbb += temp * 1;
        C0 = C0 + 16;  // Move output by 16 elements
    }
    // Handle remainder with simplified logic
    BLASLONG rem = bm & 15;
    if (rem >= 8) {
        ptrbb = bb;
        res0_0 = res0_1 = res0_2 = res0_3 = res0_4 = res0_5 = res0_6 = res0_7 = 0;
        temp = off + 1;
        for (k = 0; k < temp; k++) {
            b0 = ptrbb[0];
            a0 = ptrba[0]; res0_0 += a0 * b0;
            a1 = ptrba[1]; res0_1 += a1 * b0;
            a0 = ptrba[2]; res0_2 += a0 * b0;
            a1 = ptrba[3]; res0_3 += a1 * b0;
            a0 = ptrba[4]; res0_4 += a0 * b0;
            a1 = ptrba[5]; res0_5 += a1 * b0;
            a0 = ptrba[6]; res0_6 += a0 * b0;
            a1 = ptrba[7]; res0_7 += a1 * b0;
            ptrba += 8;
            ptrbb += 1;
        }
        res0_0 *= alpha; res0_1 *= alpha; res0_2 *= alpha; res0_3 *= alpha;
        res0_4 *= alpha; res0_5 *= alpha; res0_6 *= alpha; res0_7 *= alpha;
        C0[0] = res0_0; C0[1] = res0_1; C0[2] = res0_2; C0[3] = res0_3;
        C0[4] = res0_4; C0[5] = res0_5; C0[6] = res0_6; C0[7] = res0_7;
        ptrba += (bk - off - 1) * 8;
        ptrbb += (bk - off - 1);
        C0 += 8;
        rem -= 8;
    }
    if (rem & 4) {
        ptrbb = bb;
        res0_0 = res0_1 = res0_2 = res0_3 = 0;
        temp = off + 1;
        for (k = 0; k < temp; k++) {
            b0 = ptrbb[0];
            a0 = ptrba[0]; res0_0 += a0 * b0;
            a1 = ptrba[1]; res0_1 += a1 * b0;
            a0 = ptrba[2]; res0_2 += a0 * b0;
            a1 = ptrba[3]; res0_3 += a1 * b0;
            ptrba += 4;
            ptrbb += 1;
        }
        res0_0 *= alpha; res0_1 *= alpha; res0_2 *= alpha; res0_3 *= alpha;
        C0[0] = res0_0; C0[1] = res0_1; C0[2] = res0_2; C0[3] = res0_3;
        ptrba += (bk - off - 1) * 4;
        ptrbb += (bk - off - 1);
        C0 += 4;
    }
    if (rem & 2) {
        ptrbb = bb;
        res0_0 = res0_1 = 0;
        temp = off + 1;
        for (k = 0; k < temp; k++) {
            b0 = ptrbb[0];
            a0 = ptrba[0]; res0_0 += a0 * b0;
            a1 = ptrba[1]; res0_1 += a1 * b0;
            ptrba += 2;
            ptrbb += 1;
        }
        res0_0 *= alpha; res0_1 *= alpha;
        C0[0] = res0_0; C0[1] = res0_1;
        ptrba += (bk - off - 1) * 2;
        ptrbb += (bk - off - 1);
        C0 += 2;
    }
    if (rem & 1) {
        ptrbb = bb;
        res0_0 = 0;
        temp = off + 1;
        for (k = 0; k < temp; k++) {
            b0 = ptrbb[0];
            a0 = ptrba[0]; res0_0 += a0 * b0;
            ptrba += 1;
            ptrbb += 1;
        }
        res0_0 *= alpha;
        C0[0] = res0_0;
    }
    k = (bk << 1);  // Double the stride
    bb = bb + k;
    C = C + (ldc << 1);  // Advance two rows
}
}
