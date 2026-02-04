#include <stdio.h>

typedef long BLASLONG;

BLASLONG bm = 256;
BLASLONG bn = 256;
BLASLONG bk = 256;
float alphar = 1.5f;
float alphai = 0.8f;

float *ba;
float *bb;
float *C;
BLASLONG ldc = 512;

BLASLONG i;
BLASLONG j;
BLASLONG k;

float *C0;
float *C1;
float *ptrba;
float *ptrbb;

float res0;
float res1;
float res2;
float res3;
float res4;
float res5;
float res6;
float res7;

float load0;
float load1;
float load2;
float load3;
float load4;
float load5;
float load6;
float load7;

void init_vars() {
    ba = (float*)__builtin_malloc((bk * 4 + 16) * sizeof(float));
    bb = (float*)__builtin_malloc((bn * 2 * bk + 16) * sizeof(float));
    C = (float*)__builtin_malloc((ldc * bn * 2 + 16) * sizeof(float));

    for (int idx = 0; idx < (bk * 4 + 16); idx++) {
        ba[idx] = (float)(idx % 128) / 64.0f;
    }
    for (int idx = 0; idx < (bn * 2 * bk + 16); idx++) {
        bb[idx] = (float)(idx % 192) / 96.0f;
    }
    for (int idx = 0; idx < (ldc * bn * 2 + 16); idx++) {
        C[idx] = (float)(idx % 256) / 128.0f;
    }

    C0 = C;
    C1 = C + 2 * ldc;
    ptrba = ba;
    ptrbb = bb;
}