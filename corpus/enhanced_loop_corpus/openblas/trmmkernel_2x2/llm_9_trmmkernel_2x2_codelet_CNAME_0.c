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
extern BLASLONG off;
extern BLASLONG temp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (j = 0; j < bn / 2; j += 1) {
    C0 = C;
    C1 = C0 + ldc;
    ptrba = ba;
    for (i = 0; i < bm / 4; i += 1) {
        ptrbb = bb;
        res0 = res1 = res2 = res3 = 0;
        float res4 = 0, res5 = 0, res6 = 0, res7 = 0;
        temp = off + 2;
        for (k = 0; k < temp / 2; k += 1) {
            load0 = ptrba[0]; load1 = ptrbb[0];
            res0 += load0 * load1;
            load2 = ptrba[1]; 
            res1 += load2 * load1;
            load3 = ptrbb[1]; 
            res2 += load0 * load3;
            res3 += load2 * load3;

            load4 = ptrba[2]; load5 = ptrbb[2];
            res4 += load4 * load5;
            load6 = ptrba[3]; 
            res5 += load6 * load5;
            load7 = ptrbb[3]; 
            res6 += load4 * load7;
            res7 += load6 * load7;

            ptrba += 4;
            ptrbb += 4;
        }
        if (temp & 1) {
            load0 = ptrba[0]; load1 = ptrbb[0];
            res0 += load0 * load1;
            load2 = ptrba[1]; 
            res1 += load2 * load1;
            load3 = ptrbb[1]; 
            res2 += load0 * load3;
            res3 += load2 * load3;
            ptrba += 2;
            ptrbb += 2;
        }
        res0 *= alpha; res1 *= alpha; res2 *= alpha; res3 *= alpha;
        res4 *= alpha; res5 *= alpha; res6 *= alpha; res7 *= alpha;
        C0[0] = res0; C0[1] = res1; C0[2] = res4; C0[3] = res5;
        C1[0] = res2; C1[1] = res3; C1[2] = res6; C1[3] = res7;
        temp = bk - off;
        temp -= 2;
        ptrba += temp * 2;
        ptrbb += temp * 2;
        C0 += 4;
        C1 += 4;
    }
    for (i = 0; i < (bm & 3); i += 1) {
        ptrbb = bb;
        res0 = 0;
        res1 = 0;
        temp = off + 2;
        for (k = 0; k < temp; k += 1) {
            load0 = ptrba[0];
            load1 = ptrbb[0];
            res0 += load0 * load1;
            load2 = ptrbb[1];
            res1 += load0 * load2;
            ptrba++;
            ptrbb += 2;
        }
        res0 *= alpha;
        C0[0] = res0;
        res1 *= alpha;
        C1[0] = res1;
        ptrba += (bk - off - 2);
        ptrbb += (bk - off - 2) * 2;
        C0++;
        C1++;
    }
    k = bk << 1;
    bb += k;
    i = ldc << 1;
    C += i;
}
}
