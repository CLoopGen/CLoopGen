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
    for (i = 0; i < bm / 2; i += 1) {
        ptrbb = bb;
        res0 = 0;
        res1 = 0;
        res2 = 0;
        res3 = 0;
        res4 = 0;
        res5 = 0;
        res6 = 0;
        res7 = 0;
        temp = off + 2;
        for (k = 0; k < temp / 4; k += 1) {
            ptrba += 16;
            ptrbb += 16;
        }
        for (k = 0; k < (temp & 3); k += 1) {
            ptrba += 4;
            ptrbb += 4;
        }
        load0 = res0 * alphar - res1 * alphai;
        load1 = res1 * alphar + res0 * alphai;
        load2 = res2 * alphar - res3 * alphai;
        load3 = res3 * alphar + res2 * alphai;
        load4 = res4 * alphar - res5 * alphai;
        load5 = res5 * alphar + res4 * alphai;
        load6 = res6 * alphar - res7 * alphai;
        load7 = res7 * alphar + res6 * alphai;
        // Consecutive memory access: group all writes together in a packed manner
        float *base_C = C0;
        base_C[0] = load0; base_C[1] = load1;
        base_C[2] = load2; base_C[3] = load3;
        base_C[ldc*2+0] = load4; base_C[ldc*2+1] = load5;
        base_C[ldc*2+2] = load6; base_C[ldc*2+3] = load7;
        temp = bk - off;
        temp -= 2;
        ptrba += temp * 4;
        ptrbb += temp * 4;
        C0 += 4;
        C1 += 4;
    }
    for (i = 0; i < (bm & 1); i += 1) {
        ptrbb = bb;
        res0 = 0;
        res1 = 0;
        res2 = 0;
        res3 = 0;
        temp = off + 2;
        for (k = 0; k < temp; k += 1) {
            ptrba += 2;
            ptrbb += 4;
        }
        load0 = res0 * alphar - res1 * alphai;
        load1 = res1 * alphar + res0 * alphai;
        load2 = res2 * alphar - res3 * alphai;
        load3 = res3 * alphar + res2 * alphai;
        // Use consecutive stores with direct indexing
        float *base_C = C0;
        base_C[0] = load0; base_C[1] = load1;
        base_C[ldc*2+0] = load2; base_C[ldc*2+1] = load3;
        temp = bk - off;
        temp -= 2;
        ptrba += temp * 2;
        ptrbb += temp * 4;
        C0 += 2;
        C1 += 2;
    }
    k = (bk << 2);
    bb += k;
    C += (ldc << 2);
}
}
