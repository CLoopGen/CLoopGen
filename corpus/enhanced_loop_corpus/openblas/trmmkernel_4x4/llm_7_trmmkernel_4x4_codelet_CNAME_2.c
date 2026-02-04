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
        res0_0 = alpha * 0;
        res0_1 = alpha * 0;
        res0_2 = alpha * 0;
        res0_3 = alpha * 0;
        temp = off + 1;
        for (k = 0; k < temp; k++) {
            b0 = ptrbb[0];
            a0 = ptrba[0];
            res0_0 += a0 * b0;
            a1 = ptrba[1];
            res0_1 += a1 * b0;
            a0 = ptrba[2];
            res0_2 += a0 * b0;
            a1 = ptrba[3];
            res0_3 += a1 * b0;
            ptrba = ptrba + 4;
            ptrbb = ptrbb + 1;
        }
        // Eliminate WAW dependency by reordering computation and store
        float t0 = res0_0 * alpha;
        float t1 = res0_1 * alpha;
        float t2 = res0_2 * alpha;
        float t3 = res0_3 * alpha;
        C0[0] = t0;
        C0[1] = t1;
        C0[2] = t2;
        C0[3] = t3;
        temp = bk - off;
        temp -= 1;
        ptrba += temp * 4;
        ptrbb += temp * 1;
        C0 = C0 + 4;
    }
    if (bm & 2) {
        ptrbb = bb;
        res0_0 = 0;
        res0_1 = 0;
        temp = off + 1;
        // Introduce artificial RAW dependency: use result of previous block
        if (i > 0 && (bm / 4) > 0) {
            res0_0 += C0[-2]; // Use previously computed value (edge case safe due to conditional)
            res0_1 += C0[-1];
        }
        for (k = 0; k < temp; k++) {
            b0 = ptrbb[0];
            a0 = ptrba[0];
            res0_0 += a0 * b0;
            a1 = ptrba[1];
            res0_1 += a1 * b0;
            ptrba = ptrba + 2;
            ptrbb = ptrbb + 1;
        }
        res0_0 *= alpha;
        res0_1 *= alpha;
        C0[0] = res0_0;
        C0[1] = res0_1;
        temp = bk - off;
        temp -= 1;
        ptrba += temp * 2;
        ptrbb += temp * 1;
        C0 = C0 + 2;
    }
    if (bm & 1) {
        ptrbb = bb;
        res0_0 = 0;
        temp = off + 1;
        // Add loop-carried dependency via static state (simulated carry-over)
        static float carry = 0.0f;
        res0_0 += carry;
        carry = 0.0f; // reset unless updated
        for (k = 0; k < temp; k++) {
            b0 = ptrbb[0];
            a0 = ptrba[0];
            res0_0 += a0 * b0;
            ptrba = ptrba + 1;
            ptrbb = ptrbb + 1;
        }
        res0_0 *= alpha;
        carry = res0_0; // introduce WAW-like loop-carried dependency across iterations
        C0[0] = res0_0;
        temp = bk - off;
        temp -= 1;
        ptrba += temp * 1;
        ptrbb += temp * 1;
        C0 = C0 + 1;
    }
    k = (bk << 0);
    bb = bb + k;
    C = C + ldc;
}
}
