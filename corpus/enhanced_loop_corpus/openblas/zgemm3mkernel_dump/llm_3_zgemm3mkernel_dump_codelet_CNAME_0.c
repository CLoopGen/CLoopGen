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
for (j = 0; j < bn / 2; j += 1) {
    C0 = C;
    C1 = C0 + 2 * ldc;
    ptrba = ba;
    for (i = 0; i < bm / 2; i += 1) {
        ptrbb = bb;
        res0 = 0;
        res1 = 0;
        res2 = 0;
        res3 = 0;
        res4 = 0;
        res5 = 0;
        res6 = 0;
        res7 = 0;
        for (k = 0; k < bk / 4; k += 1) {
            res0 += ptrba[0] * ptrbb[0] + ptrba[1] * ptrbb[1];
            res1 += ptrba[0] * ptrbb[1] - ptrba[1] * ptrbb[0];
            res2 += ptrba[2] * ptrbb[2] + ptrba[3] * ptrbb[3];
            res3 += ptrba[2] * ptrbb[3] - ptrba[3] * ptrbb[2];
            res4 += ptrba[4] * ptrbb[4] + ptrba[5] * ptrbb[5];
            res5 += ptrba[4] * ptrbb[5] - ptrba[5] * ptrbb[4];
            res6 += ptrba[6] * ptrbb[6] + ptrba[7] * ptrbb[7];
            res7 += ptrba[6] * ptrbb[7] - ptrba[7] * ptrbb[6];
            ptrba = ptrba + 8;
            ptrbb = ptrbb + 8;
        }
        for (k = 0; k < (bk & 3); k += 1) {
            res0 += ptrba[0] * ptrbb[0];
            res1 += ptrba[0] * ptrbb[1];
            ptrba = ptrba + 2;
            ptrbb = ptrbb + 4;
        }
        load0 = res0 * alphar;
        C0[0] = C0[0] + load0;
        load1 = res1 * alphar;
        C0[1] = C0[1] + load1;
        load0 = res1 * alphai;
        C0[0] = C0[0] - load0;
        load1 = res0 * alphai;
        C0[1] = C0[1] + load1;
        load2 = res2 * alphar;
        C0[2] = C0[2] + load2;
        load3 = res3 * alphar;
        C0[3] = C0[3] + load3;
        load2 = res3 * alphai;
        C0[2] = C0[2] - load2;
        load3 = res2 * alphai;
        C0[3] = C0[3] + load3;
        load4 = res4 * alphar;
        C1[0] = C1[0] + load4;
        load5 = res5 * alphar;
        C1[1] = C1[1] + load5;
        load4 = res5 * alphai;
        C1[0] = C1[0] - load4;
        load5 = res4 * alphai;
        C1[1] = C1[1] + load5;
        load6 = res6 * alphar;
        C1[2] = C1[2] + load6;
        load7 = res7 * alphar;
        C1[3] = C1[3] + load7;
        load6 = res7 * alphai;
        C1[2] = C1[2] - load6;
        load7 = res6 * alphai;
        C1[3] = C1[3] + load7;
        C0 = C0 + 4;
        C1 = C1 + 4;
    }
    for (i = 0; i < (bm & 1); i += 1) {
        ptrbb = bb;
        res0 = 0;
        res1 = 0;
        res2 = 0;
        res3 = 0;
        for (k = 0; k < bk; k += 1) {
            res0 += ptrba[0] * ptrbb[0];
            res1 += ptrba[0] * ptrbb[1];
            res2 += ptrba[1] * ptrbb[2];
            res3 += ptrba[1] * ptrbb[3];
            ptrba = ptrba + 2;
            ptrbb = ptrbb + 4;
        }
        load0 = res0 * alphar;
        C0[0] = C0[0] + load0;
        load1 = res1 * alphar;
        C0[1] = C0[1] + load1;
        load0 = res1 * alphai;
        C0[0] = C0[0] - load0;
        load1 = res0 * alphai;
        C0[1] = C0[1] + load1;
        load2 = res2 * alphar;
        C1[0] = C1[0] + load2;
        load3 = res3 * alphar;
        C1[1] = C1[1] + load3;
        load2 = res3 * alphai;
        C1[0] = C1[0] - load2;
        load3 = res2 * alphai;
        C1[1] = C1[1] + load3;
        C0 = C0 + 2;
        C1 = C1 + 2;
    }
    k = (bk << 2);
    bb = bb + k;
    i = (ldc << 2);
    C = C + i;
}
}
