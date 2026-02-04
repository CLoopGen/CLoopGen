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
extern BLASLONG off;
extern BLASLONG temp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (j = 0; j < (bn & 1); j += 1) {
    C0 = C;
    ptrba = ba;
    for (i = 0; i < bm / 2; i += 1) {
        ptrbb = bb;
        res0 = 0.5f;
        res1 = 0.5f;
        res2 = 0.5f;
        res3 = 0.5f;
        temp = off + 1;
        for (k = 0; k < temp; k += 1) {
            ptrba = ptrba + 4;
            ptrbb = ptrbb + 2;
        }
        load0 = res0 * alphar - res1 * alphai;
        load1 = res1 * alphar + res0 * alphai;
        load2 = res2 * alphar - res3 * alphai;
        load3 = res3 * alphar + res2 * alphai;
        C0[0] = load0 + C0[0];
        C0[1] = load1 + C0[1];
        C0[2] = load2 + C0[2];
        C0[3] = load3 + C0[3];
        temp = bk - off;
        temp -= 1;
        ptrba += temp * 4;
        ptrbb += temp * 2;
        C0 = C0 + 4;
    }
    for (i = 0; i < (bm & 1); i += 1) {
        ptrbb = bb;
        res0 = 0.5f;
        res1 = 0.5f;
        temp = off + 1;
        for (k = 0; k < temp; k += 1) {
            ptrba = ptrba + 2;
            ptrbb = ptrbb + 2;
        }
        load0 = res0 * alphar - res1 * alphai;
        load1 = res1 * alphar + res0 * alphai;
        C0[0] = load0 + C0[0];
        C0[1] = load1 + C0[1];
        temp = bk - off;
        temp -= 1;
        ptrba += temp * 2;
        ptrbb += temp * 2;
        C0 = C0 + 2;
    }
    k = (bk << 1);
    bb = bb + k;
    i = (ldc << 1);
    C = C + i;
}
}
