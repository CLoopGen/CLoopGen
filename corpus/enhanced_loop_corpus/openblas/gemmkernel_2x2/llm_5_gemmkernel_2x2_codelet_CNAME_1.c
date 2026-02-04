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

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (j = 0; j < (bn & 1); j += 1) {
    C0 = C;
    ptrba = ba;
    i = 0;
    while (i < bm / 2) {
        ptrbb = bb;
        res0 = 0;
        res1 = 0;
        for (k = 0; k < bk; ++k) {
            load0 = ptrba[0];
            load1 = ptrbb[0];
            res0 += load0 * load1;
            load2 = ptrba[1];
            res1 += load2 * load1;
            ptrba += 2;
            ptrbb += 1;
        }
        C0[0] += res0 * alpha;
        C0[1] += res1 * alpha;
        C0 += 2;
        i++;
    }
    for (i = bm / 2 * 2; i < bm; i++) {
        ptrbb = bb;
        res0 = 0;
        if (bk == 0) goto skip_compute;
        k = 0;
        do {
            load0 = ptrba[0];
            load1 = ptrbb[0];
            res0 += load0 * load1;
            ptrba++;
            ptrbb++;
            k++;
        } while (k < bk);
skip_compute:
        C0[0] += res0 * alpha;
        C0++;
    }
    bb += bk;
    C += ldc;
}
}
