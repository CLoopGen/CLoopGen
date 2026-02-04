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
        BLASLONG kk = bk / 4;
        if (kk > 0) {
            load0 = ptrba[0];
            load2 = ptrba[1];
            load1 = ptrbb[0];
            load3 = ptrbb[1];
            res0 = load0 * load1;
            res1 = load2 * load1;
            res2 = load0 * load3;
            res3 = load2 * load3;
            ptrba += 8;
            ptrbb += 8;
            for (k = 1; k < kk; k++) {
                float temp0 = ptrba[0], temp2 = ptrba[1];
                float temp1 = ptrbb[0], temp3 = ptrbb[1];
                res0 += temp0 * temp1;
                res1 += temp2 * temp1;
                res2 += temp0 * temp3;
                res3 += temp2 * temp3;

                float temp4 = ptrba[2], temp6 = ptrba[3];
                float temp5 = ptrbb[2], temp7 = ptrbb[3];
                res0 += temp4 * temp5;
                res1 += temp6 * temp5;
                res2 += temp4 * temp7;
                res3 += temp6 * temp7;

                float temp8 = ptrba[4], temp10 = ptrba[5];
                float temp9 = ptrbb[4], temp11 = ptrbb[5];
                res0 += temp8 * temp9;
                res1 += temp10 * temp9;
                res2 += temp8 * temp11;
                res3 += temp10 * temp11;

                float temp12 = ptrba[6], temp14 = ptrba[7];
                float temp13 = ptrbb[6], temp15 = ptrbb[7];
                res0 += temp12 * temp13;
                res1 += temp14 * temp13;
                res2 += temp12 * temp15;
                res3 += temp14 * temp15;

                ptrba += 8;
                ptrbb += 8;
            }
        }
        for (k = 0; k < (bk & 3); k += 1) {
            load0 = ptrba[0];
            load1 = ptrbb[0];
            res0 = res0 + load0 * load1;
            load2 = ptrba[1];
            res1 = res1 + load2 * load1;
            load3 = ptrbb[1];
            res2 = res2 + load0 * load3;
            res3 = res3 + load2 * load3;
            ptrba = ptrba + 2;
            ptrbb = ptrbb + 2;
        }
        res0 = res0 * alpha;
        C0[0] = C0[0] + res0;
        res1 = res1 * alpha;
        C0[1] = C0[1] + res1;
        res2 = res2 * alpha;
        C1[0] = C1[0] + res2;
        res3 = res3 * alpha;
        C1[1] = C1[1] + res3;
        C0 = C0 + 2;
        C1 = C1 + 2;
    }
    for (i = 0; i < (bm & 1); i += 1) {
        ptrbb = bb;
        res0 = 0;
        res1 = 0;
        for (k = 0; k < bk; k += 1) {
            load0 = ptrba[0];
            load1 = ptrbb[0];
            res0 = res0 + load0 * load1;
            load2 = ptrbb[1];
            res1 = res1 + load0 * load2;
            ptrba = ptrba + 1;
            ptrbb = ptrbb + 2;
        }
        res0 = res0 * alpha;
        C0[0] = C0[0] + res0;
        res1 = res1 * alpha;
        C1[0] = C1[0] + res1;
        C0 = C0 + 1;
        C1 = C1 + 1;
    }
    k = (bk << 1);
    bb = bb + k;
    i = (ldc << 1);
    C = C + i;
}
}
