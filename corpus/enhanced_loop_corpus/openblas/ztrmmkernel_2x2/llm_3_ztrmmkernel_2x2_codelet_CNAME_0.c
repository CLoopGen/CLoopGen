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
for (j = 0; j < bn / 2; j += 1) {
    C0 = C;
    C1 = C0 + 2 * ldc;
    ptrba = ba;
    // Change memory access pattern to strided by unrolling and reordering accesses
    for (i = 0; i < bm / 2; i += 1) {
        ptrbb = bb;
        res0 = res1 = res2 = res3 = res4 = res5 = res6 = res7 = 0;
        temp = off + 2;

        // Simulate strided traversal: process every 4th block first, then step through
        BLASLONG stride = 4;
        for (k = 0; k < temp / 4; k += 1) {
            ptrba += stride * 4;
            ptrbb += stride * 4;
        }
        for (k = 0; k < (temp & 3); k += 1) {
            ptrba += 4;
            ptrbb += 4;
        }

        // Perform computation as before
        load0 = res0 * alphar - res1 * alphai;
        load1 = res1 * alphar + res0 * alphai;
        load2 = res2 * alphar - res3 * alphai;
        load3 = res3 * alphar + res2 * alphai;
        load4 = res4 * alphar - res5 * alphai;
        load5 = res5 * alphar + res4 * alphai;
        load6 = res6 * alphar - res7 * alphai;
        load7 = res7 * alphar + res6 * alphai;

        // Strided write: interleave results across rows and columns
        float *dst = C0;
        dst[0*ldc + 0] = load0;
        dst[1*ldc + 0] = load2;
        dst[0*ldc + 1] = load1;
        dst[1*ldc + 1] = load3;
        dst[2*ldc + 0] = load4;
        dst[3*ldc + 0] = load6;
        dst[2*ldc + 1] = load5;
        dst[3*ldc + 1] = load7;

        temp = bk - off - 2;
        ptrba += temp * 4;
        ptrbb += temp * 4;
        C0 += 4;
        C1 += 4;
    }
    for (i = 0; i < (bm & 1); i += 1) {
        ptrbb = bb;
        res0 = res1 = res2 = res3 = 0;
        temp = off + 2;
        for (k = 0; k < temp; k += 1) {
            ptrba += 2;
            ptrbb += 4;
        }
        load0 = res0 * alphar - res1 * alphai;
        load1 = res1 * alphar + res0 * alphai;
        load2 = res2 * alphar - res3 * alphai;
        load3 = res3 * alphar + res2 * alphai;

        // Strided output: scatter values non-consecutively
        float *dst = C0;
        dst[0*ldc + 0] = load0;
        dst[0*ldc + 1] = load1;
        dst[2*ldc + 0] = load2;
        dst[2*ldc + 1] = load3;

        temp = bk - off - 2;
        ptrba += temp * 2;
        ptrbb += temp * 4;
        C0 += 2;
        C1 += 2;
    }
    bb += (bk << 2);
    C += (ldc << 2);
}
}
