#include <stdio.h>
#include <stdlib.h>

typedef long BLASLONG;

BLASLONG bm = 1024;
BLASLONG bn = 2;
BLASLONG bk = 1024;
float alphar = 1.5f;
float alphai = 0.5f;
float *ba;
float *bb;
float *C;
BLASLONG ldc = 1024;
BLASLONG i;
BLASLONG j;
BLASLONG k;
float *C0;
float *ptrba;
float *ptrbb;
float res0;
float res1;
float res2;
float res3;
float load0;
float load1;
float load2;
float load3;

void init_vars() {
    ba = (float*)calloc(4 * bk + 8, sizeof(float));
    bb = (float*)calloc(2 * bk + 8, sizeof(float));
    C = (float*)calloc((ldc * bn + 8), sizeof(float));
}