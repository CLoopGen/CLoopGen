#include <stdio.h>
#include <stdlib.h>

typedef long BLASLONG;

BLASLONG bm = 1024;
BLASLONG bn = 1024;
BLASLONG bk = 1024;
float alpha = 1.5f;
float *ba;
float *bb;
float *C;
BLASLONG ldc = 1024;
BLASLONG i;
BLASLONG j;
BLASLONG k;
float *C0;
float *C1;
float *ptrba;
float *ptrbb;
float res0_0;
float res0_1;
float res0_2;
float res0_3;
float res0_4;
float res0_5;
float res0_6;
float res0_7;
float res1_0;
float res1_1;
float res1_2;
float res1_3;
float res1_4;
float res1_5;
float res1_6;
float res1_7;
float a0;
float a1;
float b0;
float b1;
BLASLONG off = 0;
BLASLONG temp;

void init_vars() {
    ba = (float*)calloc(bk * bm, sizeof(float));
    bb = (float*)calloc(bk * bn, sizeof(float));
    C = (float*)calloc(ldc * bn, sizeof(float));

    if (!ba || !bb || !C) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }
}