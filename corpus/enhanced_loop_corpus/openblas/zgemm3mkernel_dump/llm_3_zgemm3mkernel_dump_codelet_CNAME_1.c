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
    // Use strided access with reversed traversal over bk
    for (i = 0; i < bm / 2; i += 1) {
        ptrbb = bb + (bk - 1) * 2; // point to last element pair
        res0 = 0;
        res1 = 0;
        res2 = 0;
        res3 = 0;
        for (k = 0; k < bk; k += 1) {
            // Strided backward access: improves cache behavior in some architectures
            load0 = ptrba[(bk - 1 - k) * 4 + 0];
            load1 = ptrba[(bk - 1 - k) * 4 + 1];
            load2 = ptrba[(bk - 1 - k) * 4 + 2];
            load3 = ptrba[(bk - 1 - k) * 4 + 3];
            res0 += load0 * ptrbb[-(bk - 1 - k)*2 + 0];
            res1 += load1 * ptrbb[-(bk - 1 - k)*2 + 0];
            res2 += load2 * ptrbb[-(bk - 1 - k)*2 + 1];
            res3 += load3 * ptrbb[-(bk - 1 - k)*2 + 1];
        }
        load0 = res0 * alphar;
        C0[0] = C0[0] + load0;
        load1 = res1 * alphar;
        C0[1] = C0[1] + load1;
        load0 = res1 * alphai;
        C0[0] = C0[0] - load0;
        load1 = res0 * alphai;
        C0[1] = C0[1] + load1;
        load2 = res2 * alphar;
        C0[2] = C0[2] + load2;
        load3 = res3 * alphar;
        C0[3] = C0[3] + load3;
        load2 = res3 * alphai;
        C0[2] = C0[2] - load2;
        load3 = res2 * alphai;
        C0[3] = C0[3] + load3;
        C0 = C0 + 4;
    }
    for (i = 0; i < (bm & 1); i += 1) {
        ptrbb = bb + (bk - 1) * 2;
        res0 = 0;
        res1 = 0;
        for (k = 0; k < bk; k += 1) {
            // Reverse strided access for better alignment or prefetching
            load0 = ptrba[(bk - 1 - k) * 2 + 0];
            load1 = ptrba[(bk - 1 - k) * 2 + 1];
            res0 += load0 * ptrbb[-(bk - 1 - k)*2 + 0];
            res1 += load1 * ptrbb[-(bk - 1 - k)*2 + 0];
        }
        load0 = res0 * alphar;
        C0[0] = C0[0] + load0;
        load1 = res1 * alphar;
        C0[1] = C0[1] + load1;
        load0 = res1 * alphai;
        C0[0] = C0[0] - load0;
        load1 = res0 * alphai;
        C0[1] = C0[1] + load1;
        C0 = C0 + 2;
    }
    k = (bk << 1);
    bb = bb + k;
    i = (ldc << 1);
    C = C + i;
}
}
