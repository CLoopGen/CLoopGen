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
for (j = 0; j < (bn >> 1); j += 1) {
    C0 = C;
    ptrba = ba;
    for (i = 0; i < bm; i += 1) {
        ptrbb = bb;
        res0 = 0;
        for (k = 0; k < bk; k += 2) {
            load0 = ptrba[k + 0];
            load1 = ptrbb[k + 0];
            res0 = res0 + load0 * load1;

            if (k + 1 < bk) {
                load0 = ptrba[k + 1];
                load1 = ptrbb[k + 1];
                res0 = res0 + load0 * load1;
            }
        }
        res0 = res0 * alpha;
        C0[i] = C0[i] + res0;
    }
    bb = bb + bk;
    C = C + ldc;
}
}
