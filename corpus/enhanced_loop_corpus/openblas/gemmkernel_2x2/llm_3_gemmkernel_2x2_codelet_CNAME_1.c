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
    for (i = 0; i < bm / 2; i += 1) {
        res0 = 0;
        res1 = 0;
        for (k = 0; k < bk; k += 1) {
            BLASLONG idx_a = (i * 2 + 0) * bk + k;
            BLASLONG idx_b = k;
            load0 = ba[idx_a];
            load1 = bb[idx_b];
            load2 = ba[idx_a + 1];
            res0 += load0 * load1;
            res1 += load2 * load1;
        }
        C0[0] = C0[0] + res0 * alpha;
        C0[1] = C0[1] + res1 * alpha;
        C0 += 2;
    }
    for (i = 0; i < (bm & 1); i += 1) {
        res0 = 0;
        for (k = 0; k < bk; k += 1) {
            BLASLONG idx_a = (bm / 2 * 2 + i) * bk + k;
            BLASLONG idx_b = k;
            load0 = ba[idx_a];
            load1 = bb[idx_b];
            res0 += load0 * load1;
        }
        C0[0] = C0[0] + res0 * alpha;
        C0 += 1;
    }
    bb += bk;
    C += ldc;
}
}
