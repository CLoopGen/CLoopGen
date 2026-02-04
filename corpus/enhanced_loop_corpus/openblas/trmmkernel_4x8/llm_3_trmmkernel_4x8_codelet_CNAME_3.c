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
extern float a0;
extern float a1;
extern float b0;
extern BLASLONG off;
extern BLASLONG temp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (j = 0; j < (bn & 1); j += 1) {
    C0 = C;
    ptrba = ba;
    for (i = 0; i < bm / 4; i += 1) {
        ptrbb = bb;
        res0_0 = 0;
        res0_1 = 0;
        res0_2 = 0;
        res0_3 = 0;
        temp = off + 1;
        // Change memory access pattern: precompute base offsets and use array indexing
        BLASLONG base_b = (BLASLONG)(ptrbb - bb); // Logical offset base
        for (k = 0; k < temp; k++) {
            BLASLONG idx_b = base_b + k;
            b0 = bb[idx_b]; // Indirect but predictable indexing into bb
            BLASLONG idx_a = (ptrba - ba) + k * 4; // Compute absolute index in ba
            a0 = ba[idx_a];
            a1 = ba[idx_a + 1];
            res0_0 += a0 * b0;
            res0_1 += a1 * b0;
            a0 = ba[idx_a + 2];
            a1 = ba[idx_a + 3];
            res0_2 += a0 * b0;
            res0_3 += a1 * b0;
        }
        res0_0 *= alpha;
        res0_1 *= alpha;
        res0_2 *= alpha;
        res0_3 *= alpha;
        C0[0] = res0_0;
        C0[1] = res0_1;
        C0[2] = res0_2;
        C0[3] = res0_3;
        temp = bk - off;
        temp -= 1;
        ptrba += temp * 4;
        ptrbb += temp;
        C0 = C0 + 4;
    }
    if (bm & 2) {
        ptrbb = bb;
        res0_0 = 0;
        res0_1 = 0;
        temp = off + 1;
        BLASLONG base_b = (BLASLONG)(ptrbb - bb);
        for (k = 0; k < temp; k++) {
            b0 = bb[base_b + k]; // Consecutive indexed access instead of pointer dereference
            BLASLONG idx_a = (ptrba - ba) + k * 2;
            a0 = ba[idx_a];
            a1 = ba[idx_a + 1];
            res0_0 += a0 * b0;
            res0_1 += a1 * b0;
        }
        res0_0 *= alpha;
        res0_1 *= alpha;
        C0[0] = res0_0;
        C0[1] = res0_1;
        temp = bk - off;
        temp -= 1;
        ptrba += temp * 2;
        ptrbb += temp;
        C0 = C0 + 2;
    }
    if (bm & 1) {
        ptrbb = bb;
        res0_0 = 0;
        temp = off + 1;
        BLASLONG base_b = (BLASLONG)(ptrbb - bb);
        for (k = 0; k < temp; k++) {
            b0 = bb[base_b + k];
            a0 = ba[(ptrba - ba) + k]; // Fully indexed access into ba
            res0_0 += a0 * b0;
        }
        res0_0 *= alpha;
        C0[0] = res0_0;
        temp = bk - off;
        temp -= 1;
        ptrba += temp;
        ptrbb += temp;
        C0 = C0 + 1;
    }
    k = (bk << 0);
    bb = bb + k;
    C = C + ldc;
}
}
