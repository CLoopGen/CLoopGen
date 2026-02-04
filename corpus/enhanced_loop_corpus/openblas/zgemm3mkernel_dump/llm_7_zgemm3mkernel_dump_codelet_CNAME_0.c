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

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (j = 0; j < bn / 2; j += 1) {
    C0 = C;
    C1 = C0 + 2 * ldc;
    ptrba = ba;
    for (i = 0; i < bm / 2; i += 1) {
        ptrbb = bb;
        res0 = res1 = res2 = res3 = res4 = res5 = res6 = res7 = 0.0f;
        for (k = 0; k < bk / 4; k += 1) {
            ptrba += 16;
            ptrbb += 16;
        }
        for (k = 0; k < (bk & 3); k += 1) {
            ptrba += 4;
            ptrbb += 4;
        }
        load0 = res0 * alphar;
        load1 = res1 * alphar;
        load2 = res2 * alphar;
        load3 = res3 * alphar;
        load4 = res4 * alphar;
        load5 = res5 * alphar;
        load6 = res6 * alphar;
        load7 = res7 * alphar;
        float imag0 = res1 * alphai;
        float imag1 = res0 * alphai;
        float imag2 = res3 * alphai;
        float imag3 = res2 * alphai;
        float imag4 = res5 * alphai;
        float imag5 = res4 * alphai;
        float imag6 = res7 * alphai;
        float imag7 = res6 * alphai;
        C0[0] = (C0[0] + load0) - imag0;
        C0[1] = (C0[1] + load1) + imag1;
        C0[2] = (C0[2] + load2) - imag2;
        C0[3] = (C0[3] + load3) + imag3;
        C1[0] = (C1[0] + load4) - imag4;
        C1[1] = (C1[1] + load5) + imag5;
        C1[2] = (C1[2] + load6) - imag6;
        C1[3] = (C1[3] + load7) + imag7;
        C0 += 4;
        C1 += 4;
    }
    for (i = 0; i < (bm & 1); i += 1) {
        ptrbb = bb;
        res0 = res1 = res2 = res3 = 0.0f;
        for (k = 0; k < bk; k += 1) {
            ptrba += 2;
            ptrbb += 4;
        }
        float r0a = res0 * alphar;
        float r1a = res1 * alphar;
        float r2a = res2 * alphar;
        float r3a = res3 * alphar;
        float i0a = res1 * alphai;
        float i1a = res0 * alphai;
        float i2a = res3 * alphai;
        float i3a = res2 * alphai;
        C0[0] = C0[0] + r0a - i0a;
        C0[1] = C0[1] + r1a + i1a;
        C1[0] = C1[0] + r2a - i2a;
        C1[1] = C1[1] + r3a + i3a;
        C0 += 2;
        C1 += 2;
    }
    bb += (bk << 2);
    C += (ldc << 2);
}
}
