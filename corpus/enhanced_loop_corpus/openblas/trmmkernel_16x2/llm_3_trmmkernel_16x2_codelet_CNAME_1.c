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
extern float res0_8;
extern float res0_9;
extern float res0_10;
extern float res0_11;
extern float res0_12;
extern float res0_13;
extern float res0_14;
extern float res0_15;
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
    for (i = 0; i < bm / 16; i += 1) {
        ptrbb = bb;
        res0_0 = 0;
        res0_1 = 0;
        res0_2 = 0;
        res0_3 = 0;
        res0_4 = 0;
        res0_5 = 0;
        res0_6 = 0;
        res0_7 = 0;
        res0_8 = 0;
        res0_9 = 0;
        res0_10 = 0;
        res0_11 = 0;
        res0_12 = 0;
        res0_13 = 0;
        res0_14 = 0;
        res0_15 = 0;
        temp = off + 1;
        // Consecutive memory layout simulation: transpose inner loop to iterate over multiple b values at once
        for (k = 0; k < temp; k += 1) {
            // Load 4 consecutive b-values (if available, but bounded by temp)
            float b_vals[4];
            int unroll_factor = (temp - k >= 4) ? 4 : (temp - k);
            for (int u = 0; u < unroll_factor; u++) {
                b_vals[u] = ptrbb[u];
            }

            // Accumulate using vectorized-like pattern
            for (int u = 0; u < unroll_factor; u++) {
                b0 = b_vals[u];
                a0 = ptrba[u * 16 + 0];
                res0_0 += a0 * b0;
                a1 = ptrba[u * 16 + 1];
                res0_1 += a1 * b0;
                a0 = ptrba[u * 16 + 2];
                res0_2 += a0 * b0;
                a1 = ptrba[u * 16 + 3];
                res0_3 += a1 * b0;
                a0 = ptrba[u * 16 + 4];
                res0_4 += a0 * b0;
                a1 = ptrba[u * 16 + 5];
                res0_5 += a1 * b0;
                a0 = ptrba[u * 16 + 6];
                res0_6 += a0 * b0;
                a1 = ptrba[u * 16 + 7];
                res0_7 += a1 * b0;
                a0 = ptrba[u * 16 + 8];
                res0_8 += a0 * b0;
                a1 = ptrba[u * 16 + 9];
                res0_9 += a1 * b0;
                a0 = ptrba[u * 16 + 10];
                res0_10 += a0 * b0;
                a1 = ptrba[u * 16 + 11];
                res0_11 += a1 * b0;
                a0 = ptrba[u * 16 + 12];
                res0_12 += a0 * b0;
                a1 = ptrba[u * 16 + 13];
                res0_13 += a1 * b0;
                a0 = ptrba[u * 16 + 14];
                res0_14 += a0 * b0;
                a1 = ptrba[u * 16 + 15];
                res0_15 += a1 * b0;
            }
            ptrba += 16 * unroll_factor;
            ptrbb += unroll_factor;
        }
        res0_0 *= alpha;
        res0_1 *= alpha;
        res0_2 *= alpha;
        res0_3 *= alpha;
        res0_4 *= alpha;
        res0_5 *= alpha;
        res0_6 *= alpha;
        res0_7 *= alpha;
        res0_8 *= alpha;
        res0_9 *= alpha;
        res0_10 *= alpha;
        res0_11 *= alpha;
        res0_12 *= alpha;
        res0_13 *= alpha;
        res0_14 *= alpha;
        res0_15 *= alpha;
        C0[0] = res0_0;
        C0[1] = res0_1;
        C0[2] = res0_2;
        C0[3] = res0_3;
        C0[4] = res0_4;
        C0[5] = res0_5;
        C0[6] = res0_6;
        C0[7] = res0_7;
        C0[8] = res0_8;
        C0[9] = res0_9;
        C0[10] = res0_10;
        C0[11] = res0_11;
        C0[12] = res0_12;
        C0[13] = res0_13;
        C0[14] = res0_14;
        C0[15] = res0_15;
        temp = bk - off;
        temp -= 1;
        ptrba += temp * 16;
        ptrbb += temp;
        C0 = C0 + 16;
    }
    if (bm & 8) {
        ptrbb = bb;
        res0_0 = 0;
        res0_1 = 0;
        res0_2 = 0;
        res0_3 = 0;
        res0_4 = 0;
        res0_5 = 0;
        res0_6 = 0;
        res0_7 = 0;
        temp = off + 1;
        for (k = 0; k < temp; k++) {
            b0 = ptrbb[0];
            res0_0 += ptrba[0] * b0;
            res0_1 += ptrba[1] * b0;
            res0_2 += ptrba[2] * b0;
            res0_3 += ptrba[3] * b0;
            res0_4 += ptrba[4] * b0;
            res0_5 += ptrba[5] * b0;
            res0_6 += ptrba[6] * b0;
            res0_7 += ptrba[7] * b0;
            ptrba += 8;
            ptrbb += 1;
        }
        res0_0 *= alpha;
        res0_1 *= alpha;
        res0_2 *= alpha;
        res0_3 *= alpha;
        res0_4 *= alpha;
        res0_5 *= alpha;
        res0_6 *= alpha;
        res0_7 *= alpha;
        C0[0] = res0_0;
        C0[1] = res0_1;
        C0[2] = res0_2;
        C0[3] = res0_3;
        C0[4] = res0_4;
        C0[5] = res0_5;
        C0[6] = res0_6;
        C0[7] = res0_7;
        temp = bk - off;
        temp -= 1;
        ptrba += temp * 8;
        ptrbb += temp;
        C0 += 8;
    }
    if (bm & 4) {
        ptrbb = bb;
        res0_0 = 0;
        res0_1 = 0;
        res0_2 = 0;
        res0_3 = 0;
        temp = off + 1;
        for (k = 0; k < temp; k++) {
            b0 = ptrbb[0];
            res0_0 += ptrba[0] * b0;
            res0_1 += ptrba[1] * b0;
            res0_2 += ptrba[2] * b0;
            res0_3 += ptrba[3] * b0;
            ptrba += 4;
            ptrbb += 1;
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
        C0 += 4;
    }
    if (bm & 2) {
        ptrbb = bb;
        res0_0 = 0;
        res0_1 = 0;
        temp = off + 1;
        for (k = 0; k < temp; k++) {
            b0 = ptrbb[0];
            res0_0 += ptrba[0] * b0;
            res0_1 += ptrba[1] * b0;
            ptrba += 2;
            ptrbb += 1;
        }
        res0_0 *= alpha;
        res0_1 *= alpha;
        C0[0] = res0_0;
        C0[1] = res0_1;
        temp = bk - off;
        temp -= 1;
        ptrba += temp * 2;
        ptrbb += temp;
        C0 += 2;
    }
    if (bm & 1) {
        ptrbb = bb;
        res0_0 = 0;
        temp = off + 1;
        for (k = 0; k < temp; k++) {
            b0 = ptrbb[0];
            res0_0 += ptrba[0] * b0;
            ptrba += 1;
            ptrbb += 1;
        }
        res0_0 *= alpha;
        C0[0] = res0_0;
        temp = bk - off;
        temp -= 1;
        ptrba += temp;
        ptrbb += temp;
        C0 += 1;
    }
    k = (bk << 0);
    bb += k;
    C += ldc;
}
}
