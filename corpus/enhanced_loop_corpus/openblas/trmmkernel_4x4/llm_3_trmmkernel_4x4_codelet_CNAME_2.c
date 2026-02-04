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
        // Use consecutive memory layout assumption: unroll and coalesce accesses
        for (k = 0; k < temp; k += 4) {
            float sum_b[4] = {0};
            int bound = (temp - k) >= 4 ? 4 : (temp - k);
            for (int s = 0; s < bound; ++s) {
                sum_b[s] = ptrbb[k + s];
            }
            for (int s = 0; s < bound; ++s) {
                a0 = ptrba[4*(k+s)]; 
                a1 = ptrba[4*(k+s)+1];
                res0_0 += a0 * sum_b[s];
                res0_1 += a1 * sum_b[s];
                a0 = ptrba[4*(k+s)+2];
                a1 = ptrba[4*(k+s)+3];
                res0_2 += a0 * sum_b[s];
                res0_3 += a1 * sum_b[s];
            }
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
        for (k = 0; k < temp; k++) {
            b0 = ptrbb[k]; // Consecutive indexed access for better predictability
            a0 = ptrba[2 * k];
            a1 = ptrba[2 * k + 1];
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
        for (k = 0; k < temp; k++) {
            b0 = ptrbb[k];
            a0 = ptrba[k];
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
