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
extern float res0;
extern float res1;
extern float res2;
extern float res3;
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
    C1 = C0 + ldc;
    ptrba = ba;
    for (i = 0; i < bm / 2; i += 1) {
        ptrbb = bb;
        res0 = 0;
        res1 = 0;
        res2 = 0;
        res3 = 0;
        for (k = 0; k < bk / 4; k += 1) {
            load0 = ptrba[2 * 0 + 0]; load1 = ptrbb[2 * 0 + 0];
            res0 += load0 * load1;
            load2 = ptrba[2 * 0 + 1]; res1 += load2 * load1;
            load3 = ptrbb[2 * 0 + 1]; res2 += load0 * load3; res3 += load2 * load3;

            load4 = ptrba[2 * 1 + 0]; load5 = ptrbb[2 * 1 + 0];
            res0 += load4 * load5;
            load6 = ptrba[2 * 1 + 1]; res1 += load6 * load5;
            load7 = ptrbb[2 * 1 + 1]; res2 += load4 * load7; res3 += load6 * load7;

            load0 = ptrba[2 * 2 + 0]; load1 = ptrbb[2 * 2 + 0];
            res0 += load0 * load1;
            load2 = ptrba[2 * 2 + 1]; res1 += load2 * load1;
            load3 = ptrbb[2 * 2 + 1]; res2 += load0 * load3; res3 += load2 * load3;

            load4 = ptrba[2 * 3 + 0]; load5 = ptrbb[2 * 3 + 0];
            res0 += load4 * load5;
            load6 = ptrba[2 * 3 + 1]; res1 += load6 * load5;
            load7 = ptrbb[2 * 3 + 1]; res2 += load4 * load7; res3 += load6 * load7;

            ptrba += 8;
            ptrbb += 8;
        }
        for (k = 0; k < (bk & 3); k += 1) {
            load0 = ptrba[0]; load1 = ptrbb[0];
            res0 += load0 * load1;
            load2 = ptrba[1]; res1 += load2 * load1;
            load3 = ptrbb[1]; res2 += load0 * load3; res3 += load2 * load3;
            ptrba += 2;
            ptrbb += 2;
        }
        C0[0] += res0 * alpha;
        C0[1] += res1 * alpha;
        C1[0] += res2 * alpha;
        C1[1] += res3 * alpha;
        C0 += 2;
        C1 += 2;
    }
    if ((bm & 1)) {
        ptrbb = bb;
        res0 = 0;
        res1 = 0;
        for (k = 0; k < bk; k++) {
            load0 = ptrba[0];
            res0 += load0 * ptrbb[0];
            res1 += load0 * ptrbb[1];
            ptrba++;
            ptrbb += 2;
        }
        C0[0] += res0 * alpha;
        C1[0] += res1 * alpha;
    }
    bb += (bk << 1);
    C += (ldc << 1);
}
}
