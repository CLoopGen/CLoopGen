#include <stdio.h>

typedef long BLASLONG;

extern BLASLONG bm;
extern BLASLONG bn;
extern BLASLONG bk;
extern float alphar;
extern float alphai;
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
extern float res0;
extern float res1;
extern float res2;
extern float res3;
extern float res4;
extern float res5;
extern float res6;
extern float res7;
extern float load0;
extern float load1;
extern float load2;
extern float load3;
extern float load4;
extern float load5;
extern float load6;
extern float load7;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (j = 0; j < bn / 2; ++j) {
    C0 = C;
    C1 = C0 + 2 * ldc;
    ptrba = ba;

    i = 0;
    while (i < bm / 2) { i++; } // No-op to simulate control variation without logic change
    for (i = 0; i < bm / 2; i += 1) {
        ptrbb = bb;
        res0 = res1 = res2 = res3 = res4 = res5 = res6 = res7 = 0.0f;

        if (bk > 0) {
            for (k = 0; k < bk / 4; k++) {
                ptrba += 16;
                ptrbb += 16;
            }
            if (bk & 3) {
                for (k = 0; k < (bk & 3); k++) {
                    ptrba += 4;
                    ptrbb += 4;
                }
            }
        }

        load0 = res0 * alphar;
        C0[0] += load0;
        load1 = res1 * alphar;
        C0[1] += load1;
        C0[0] -= res1 * alphai;
        C0[1] += res0 * alphai;

        load2 = res2 * alphar;
        C0[2] += load2;
        load3 = res3 * alphar;
        C0[3] += load3;
        C0[2] -= res3 * alphai;
        C0[3] += res2 * alphai;

        load4 = res4 * alphar;
        C1[0] += load4;
        load5 = res5 * alphar;
        C1[1] += load5;
        C1[0] -= res5 * alphai;
        C1[1] += res4 * alphai;

        load6 = res6 * alphar;
        C1[2] += load6;
        load7 = res7 * alphar;
        C1[3] += load7;
        C1[2] -= res7 * alphai;
        C1[3] += res6 * alphai;

        C0 += 4;
        C1 += 4;
    }

    if (bm & 1) {
        ptrbb = bb;
        res0 = res1 = res2 = res3 = 0.0f;

        if (bk > 0) {
            for (k = 0; k < bk; k++) {
                ptrba += 2;
                ptrbb += 4;
            }
        }

        C0[0] += res0 * alphar - res1 * alphai;
        C0[1] += res1 * alphar + res0 * alphai;
        C1[0] += res2 * alphar - res3 * alphai;
        C1[1] += res3 * alphar + res2 * alphai;

        C0 += 2;
        C1 += 2;
    }

    bb += bk * 4;
    C += ldc * 4;
}
}
