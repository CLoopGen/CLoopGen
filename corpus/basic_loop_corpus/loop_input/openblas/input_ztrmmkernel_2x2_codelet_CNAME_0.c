#include <stdio.h>
#include <stdlib.h>

typedef long BLASLONG;

BLASLONG bm = 256;
BLASLONG bn = 256;
BLASLONG bk = 256;
float alphar = 1.0f;
float alphai = 0.5f;
float *ba;
float *bb;
float *C;
BLASLONG ldc = 256;
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
BLASLONG off = 0;
BLASLONG temp;

void init_vars() {
    ba = (float*)calloc(bk * bm * 4, sizeof(float));
    bb = (float*)calloc(bk * bn * 4, sizeof(float));
    C = (float*)calloc(ldc * bn * 4, sizeof(float));
}