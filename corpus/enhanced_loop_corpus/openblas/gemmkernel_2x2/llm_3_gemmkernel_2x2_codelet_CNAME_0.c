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
        BLASLONG idx_ba_base, idx_bb_base;
        for (k = 0; k < bk / 4; k += 1) {
            idx_ba_base = 8 * k;
            idx_bb_base = 8 * k;
            load0 = ptrba[idx_ba_base + 0];
            load1 = ptrbb[idx_bb_base + 0];
            res0 = res0 + load0 * load1;
            load2 = ptrba[idx_ba_base + 1];
            res1 = res1 + load2 * load1;
            load3 = ptrbb[idx_bb_base + 1];
            res2 = res2 + load0 * load3;
            res3 = res3 + load2 * load3;

            load4 = ptrba[idx_ba_base + 2];
            load5 = ptrbb[idx_bb_base + 2];
            res0 = res0 + load4 * load5;
            load6 = ptrba[idx_ba_base + 3];
            res1 = res1 + load6 * load5;
            load7 = ptrbb[idx_bb_base + 3];
            res2 = res2 + load4 * load7;
            res3 = res3 + load6 * load7;

            load0 = ptrba[idx_ba_base + 4];
            load1 = ptrbb[idx_bb_base + 4];
            res0 = res0 + load0 * load1;
            load2 = ptrba[idx_ba_base + 5];
            res1 = res1 + load2 * load1;
            load3 = ptrbb[idx_bb_base + 5];
            res2 = res2 + load0 * load3;
            res3 = res3 + load2 * load3;

            load4 = ptrba[idx_ba_base + 6];
            load5 = ptrbb[idx_bb_base + 6];
            res0 = res0 + load4 * load5;
            load6 = ptrba[idx_ba_base + 7];
            res1 = res1 + load6 * load5;
            load7 = ptrbb[idx_bb_base + 7];
            res2 = res2 + load4 * load7;
            res3 = res3 + load6 * load7;
        }
        for (k = 0; k < (bk & 3); k += 1) {
            BLASLONG offset = 8 * (bk / 4) + 2 * k;
            load0 = ptrba[offset + 0];
            load1 = ptrbb[offset + 0];
            res0 = res0 + load0 * load1;
            load2 = ptrba[offset + 1];
            res1 = res1 + load2 * load1;
            load3 = ptrbb[offset + 1];
            res2 = res2 + load0 * load3;
            res3 = res3 + load2 * load3;
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
            BLASLONG off_ba = (ptrba - ba) + 0;
            BLASLONG off_bb = (ptrbb - bb) + 0;
            load0 = ba[off_ba];
            load1 = bb[off_bb + 0];
            res0 = res0 + load0 * load1;
            load2 = bb[off_bb + 1];
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
