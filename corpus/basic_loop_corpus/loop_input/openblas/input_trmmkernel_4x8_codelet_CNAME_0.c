#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef long BLASLONG;

BLASLONG bm = 1024;
BLASLONG bn = 1024;
BLASLONG bk = 1024;
float alpha = 1.5f;
float *ba;
float *bb;
float *C;
BLASLONG ldc = 1024;
BLASLONG offset = 0;
BLASLONG i;
BLASLONG j;
BLASLONG k;
float *C0;
float *C1;
float *C2;
float *C3;
float *C4;
float *C5;
float *C6;
float *C7;
float *ptrba;
float *ptrbb;
float res0_0;
float res0_1;
float res0_2;
float res0_3;
float res1_0;
float res1_1;
float res1_2;
float res1_3;
float res2_0;
float res2_1;
float res2_2;
float res2_3;
float res3_0;
float res3_1;
float res3_2;
float res3_3;
float res4_0;
float res4_1;
float res4_2;
float res4_3;
float res5_0;
float res5_1;
float res5_2;
float res5_3;
float res6_0;
float res6_1;
float res6_2;
float res6_3;
float res7_0;
float res7_1;
float res7_2;
float res7_3;
float a0;
float a1;
float b0;
float b1;
float b2;
float b3;
float b4;
float b5;
float b6;
float b7;
BLASLONG off;
BLASLONG temp;
_Bool left = 0;
_Bool backwards = 0;

void init_vars() {
    size_t size_ba = (size_t)bm * bk * sizeof(float);
    size_t size_bb = (size_t)bk * bn * sizeof(float);
    size_t size_C = (size_t)ldc * bn * sizeof(float);

    ba = (float*)aligned_alloc(32, size_ba);
    bb = (float*)aligned_alloc(32, size_bb);
    C = (float*)aligned_alloc(32, size_C);

    if (!ba || !bb || !C) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    for (size_t idx = 0; idx < (size_t)bm * bk; idx++) {
        ba[idx] = (float)((idx % 100) / 100.0);
    }
    for (size_t idx = 0; idx < (size_t)bk * bn; idx++) {
        bb[idx] = (float)((idx % 100) / 50.0);
    }
    for (size_t idx = 0; idx < (size_t)ldc * bn; idx++) {
        C[idx] = 0.0f;
    }

    ptrba = ba;
    ptrbb = bb;
    offset = 0;
    left = 0;
    backwards = 0;
}