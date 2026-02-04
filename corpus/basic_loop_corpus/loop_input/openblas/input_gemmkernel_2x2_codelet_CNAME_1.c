#include <stdio.h>
#include <stdlib.h>

typedef long BLASLONG;

BLASLONG bm = 256;
BLASLONG bn = 1;
BLASLONG bk = 256;
float alpha = 1.5f;
float *ba;
float *bb;
float *C;
BLASLONG ldc = 256;
BLASLONG i;
BLASLONG j;
BLASLONG k;
float *C0;
float *ptrba;
float *ptrbb;
float res0;
float res1;
float load0;
float load1;
float load2;

void init_vars() {
    ba = (float*)calloc(bm * bk, sizeof(float));
    bb = (float*)calloc(bk * bn, sizeof(float));
    C = (float*)calloc(ldc * bn, sizeof(float));
    if (!ba || !bb || !C) {
        exit(1);
    }
}