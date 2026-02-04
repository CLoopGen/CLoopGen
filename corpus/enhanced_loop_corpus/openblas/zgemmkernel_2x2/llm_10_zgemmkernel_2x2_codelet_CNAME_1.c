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
extern float *ptrba;
extern float *ptrbb;
extern float res0;
extern float res1;
extern float res2;
extern float res3;
extern float load0;
extern float load1;
extern float load2;
extern float load3;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (j = 0; j < (bn >> 1); j += 1) {
    C0 = C;
    ptrba = ba;
    for (i = 0; i < bm / 2; i += 1) {
        ptrbb = bb;
        res0 = 0;
        res1 = 0;
        res2 = 0;
        res3 = 0;
        for (k = 0; k < (bk >> 1); k += 1) {
            ptrba = ptrba + 8;
            ptrbb = ptrbb + 4;
            res0 += ptrba[-7] * ptrbb[-3] - ptrba[-6] * ptrbb[-2];
            res1 += ptrba[-6] * ptrbb[-3] + ptrba[-7] * ptrbb[-2];
            res2 += ptrba[-5] * ptrbb[-3] - ptrba[-4] * ptrbb[-2];
            res3 += ptrba[-4] * ptrbb[-3] + ptrba[-5] * ptrbb[-2];
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
        C0 = C0 + 4;
    }
    for (i = 0; i < (bm & 1); i += 1) {
        ptrbb = bb;
        res0 = 0;
        res1 = 0;
        for (k = 0; k < bk; k += 1) {
            ptrba = ptrba + 2;
            ptrbb = ptrbb + 2;
        }
        load0 = res0 * alphar;
        C0[0] = C0[0] + load0;
        load1 = res1 * alphar;
        C0[1] = C0[1] + load1;
        load0 = res1 * alphai;
        C0[0] = C0[0] - load0;
        load1 = res0 * alphai;
        C0[1] = C0[1] + load1;
        C0 = C0 + 2;
    }
    k = (bk << 1);
    bb = bb + (k << 1);
    i = (ldc << 1);
    C = C + i;
}
}
