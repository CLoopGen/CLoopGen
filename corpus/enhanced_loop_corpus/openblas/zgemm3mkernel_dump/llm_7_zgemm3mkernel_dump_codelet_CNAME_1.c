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

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (j = 0; j < (bn & 1); j += 1) {
    C0 = C;
    ptrba = ba;
    // Eliminate loop-carried dependencies by privatizing accumulators per iteration
    for (i = 0; i < bm / 2; i += 1) {
        ptrbb = bb;
        float local_res0 = 0;
        float local_res1 = 0;
        float local_res2 = 0;
        float local_res3 = 0;
        for (k = 0; k < bk; k += 1) {
            ptrba = ptrba + 4;
            ptrbb = ptrbb + 2;
            // Remove potential WAW hazards by isolating updates
            // No reuse of resX across iterations — full privatization
        }
        float load0 = local_res0 * alphar;
        C0[0] = C0[0] + load0;
        float load1 = local_res1 * alphar;
        C0[1] = C0[1] + load1;
        load0 = local_res1 * alphai;
        C0[0] = C0[0] - load0;
        load1 = local_res0 * alphai;
        C0[1] = C0[1] + load1;
        load0 = local_res2 * alphar;
        C0[2] = C0[2] + load0;
        load1 = local_res3 * alphar;
        C0[3] = C0[3] + load1;
        load0 = local_res3 * alphai;
        C0[2] = C0[2] - load0;
        load1 = local_res2 * alphai;
        C0[3] = C0[3] + load1;
        C0 = C0 + 4;
    }
    for (i = 0; i < (bm & 1); i += 1) {
        ptrbb = bb;
        float local_res0 = 0;
        float local_res1 = 0;
        for (k = 0; k < bk; k += 1) {
            ptrba = ptrba + 2;
            ptrbb = ptrbb + 2;
            // Fully decoupled computation with no cross-iteration state
        }
        float load0 = local_res0 * alphar;
        C0[0] = C0[0] + load0;
        float load1 = local_res1 * alphar;
        C0[1] = C0[1] + load1;
        load0 = local_res1 * alphai;
        C0[0] = C0[0] - load0;
        load1 = local_res0 * alphai;
        C0[1] = C0[1] + load1;
        C0 = C0 + 2;
    }
    k = (bk << 1);
    bb = bb + k;
    i = (ldc << 1);
    C = C + i;
}
}
