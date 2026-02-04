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
extern BLASLONG off;
extern BLASLONG temp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (j = 0; j < bn / 2; j += 2) {
    C0 = C;
    C1 = C0 + 4 * ldc;
    ptrba = ba;
    for (i = 0; i < bm / 4; i += 1) {
        ptrbb = bb;
        res0 = res1 = res2 = res3 = res4 = res5 = res6 = res7 = 0;
        temp = off + 2;
        for (k = 0; k < temp / 4; k += 1) {
            ptrba += 16; ptrbb += 16;
        }
        for (k = 0; k < (temp & 3); k += 1) {
            ptrba += 4; ptrbb += 4;
        }
        load0 = res0 * alphar - res1 * alphai;
        load1 = res1 * alphar + res0 * alphai;
        load2 = res2 * alphar - res3 * alphai;
        load3 = res3 * alphar + res2 * alphai;
        load4 = res4 * alphar - res5 * alphai;
        load5 = res5 * alphar + res4 * alphai;
        load6 = res6 * alphar - res7 * alphai;
        load7 = res7 * alphar + res6 * alphai;
        C0[0] = load0; C0[1] = load1;
        C0[2] = load2; C0[3] = load3;
        C0[4] = load4; C0[5] = load5;
        C0[6] = load6; C0[7] = load7;
        C1[0] = load0; C1[1] = load1;
        C1[2] = load2; C1[3] = load3;
        C1[4] = load4; C1[5] = load5;
        C1[6] = load6; C1[7] = load7;
        temp = bk - off - 2;
        ptrba += temp * 4;
        ptrbb += temp * 4;
        C0 += 8;
        C1 += 8;
    }
    for (i = 0; i < (bm & 3); i += 1) {
        ptrbb = bb;
        res0 = res1 = res2 = res3 = 0;
        temp = off + 2;
        for (k = 0; k < temp; k += 1) {
            ptrba += 2; ptrbb += 4;
        }
        load0 = res0 * alphar - res1 * alphai;
        load1 = res1 * alphar + res0 * alphai;
        load2 = res2 * alphar - res3 * alphai;
        load3 = res3 * alphar + res2 * alphai;
        C0[0] = load0; C0[1] = load1;
        C1[0] = load2; C1[1] = load3;
        temp = bk - off - 2;
        ptrba += temp * 2;
        ptrbb += temp * 4;
        C0 += 2;
        C1 += 2;
    }
    k = (bk << 3);
    bb = bb + k;
    i = (ldc << 3);
    C = C + i;
}
}
