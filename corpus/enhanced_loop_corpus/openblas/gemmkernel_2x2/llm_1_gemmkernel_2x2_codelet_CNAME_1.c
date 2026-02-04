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
    for (i = 0; i < bm; i += 2) {
        ptrba = ba + i*1;
        ptrbb = bb;
        res0 = 0;
        res1 = 0;
        if (i+1 < bm) {
            for (k = 0; k < bk; k += 1) {
                load0 = ptrba[k*2 + 0];
                load1 = ptrbb[k + 0];
                res0 = res0 + load0 * load1;
                load2 = ptrba[k*2 + 1];
                res1 = res1 + load2 * load1;
            }
            res0 = res0 * alpha;
            C0[0] = C0[0] + res0;
            res1 = res1 * alpha;
            C0[1] = C0[1] + res1;
            C0 += 2;
        } else {
            res0 = 0;
            for (k = 0; k < bk; k += 1) {
                load0 = ptrba[k];
                load1 = ptrbb[k];
                res0 = res0 + load0 * load1;
            }
            res0 = res0 * alpha;
            C0[0] = C0[0] + res0;
            C0 += 1;
        }
    }
    bb = bb + bk;
    C = C + ldc;
}
}
