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
extern float res0;
extern float res1;
extern float load0;
extern float load1;
extern float load2;
extern BLASLONG off;
extern BLASLONG temp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (j = 0; j < (bn & 1); j += 1) {
    C0 = C;
    ptrba = ba;
    for (i = 0; i < bm / 4; i += 1) {
        ptrbb = bb;
        res0 = 0;
        res1 = 0;
        temp = off + 1;
        for (k = 0; k < temp; k += 1) {
            load0 = ptrba[2 * 0 + 0];
            load1 = ptrbb[0 + 0];
            res0 = res0 + load0 * load1;
            load2 = ptrba[2 * 0 + 1];
            res1 = res1 + load2 * load1;
            ptrba = ptrba + 2;
            ptrbb = ptrbb + 1;
        }
        res0 = res0 * alpha;
        res1 = res1 * alpha;
        C0[0] = res0;
        C0[1] = res1;
        temp = bk - off;
        temp -= 1;
        ptrba += temp * 2;
        ptrbb += temp;
        C0 = C0 + 2;

        // Second unrolled iteration
        ptrbb = bb;
        res0 = 0;
        res1 = 0;
        temp = off + 1;
        for (k = 0; k < temp; k += 1) {
            load0 = ptrba[2 * 0 + 0];
            load1 = ptrbb[0 + 0];
            res0 = res0 + load0 * load1;
            load2 = ptrba[2 * 0 + 1];
            res1 = res1 + load2 * load1;
            ptrba = ptrba + 2;
            ptrbb = ptrbb + 1;
        }
        res0 = res0 * alpha;
        res1 = res1 * alpha;
        C0[0] = res0;
        C0[1] = res1;
        temp = bk - off;
        temp -= 1;
        ptrba += temp * 2;
        ptrbb += temp;
        C0 = C0 + 2;
    }
    // Handle remaining blocks of size 2
    for (; i < bm / 2; i += 1) {
        ptrbb = bb;
        res0 = 0;
        res1 = 0;
        temp = off + 1;
        for (k = 0; k < temp; k += 1) {
            load0 = ptrba[2 * 0 + 0];
            load1 = ptrbb[0 + 0];
            res0 = res0 + load0 * load1;
            load2 = ptrba[2 * 0 + 1];
            res1 = res1 + load2 * load1;
            ptrba = ptrba + 2;
            ptrbb = ptrbb + 1;
        }
        res0 = res0 * alpha;
        C0[0] = res0;
        res1 = res1 * alpha;
        C0[1] = res1;
        temp = bk - off;
        temp -= 1;
        ptrba += temp * 2;
        ptrbb += temp;
        C0 = C0 + 2;
    }
    for (i = 0; i < (bm & 1); i += 1) {
        ptrbb = bb;
        res0 = 0;
        temp = off + 1;
        for (k = 0; k < temp; k += 1) {
            load0 = ptrba[0 + 0];
            load1 = ptrbb[0 + 0];
            res0 = res0 + load0 * load1;
            ptrba = ptrba + 1;
            ptrbb = ptrbb + 1;
        }
        res0 = res0 * alpha;
        C0[0] = res0;
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
