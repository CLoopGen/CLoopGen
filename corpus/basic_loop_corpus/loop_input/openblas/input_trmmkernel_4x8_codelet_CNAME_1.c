#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef long BLASLONG;

BLASLONG bm = 256;
BLASLONG bn = 8;
BLASLONG bk = 256;
float alpha = 1.1f;
float *ba;
float *bb;
float *C;
BLASLONG ldc = 256;
BLASLONG offset = 0;
BLASLONG i;
BLASLONG j;
BLASLONG k;
float *C0;
float *C1;
float *C2;
float *C3;
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
float a0;
float a1;
float b0;
float b1;
float b2;
float b3;
BLASLONG off;
BLASLONG temp;
_Bool left = 0;
_Bool backwards = 0;

void init_vars() {
    const size_t size_ba = (bm + 4) * (bk + 4);
    const size_t size_bb = (bk + 4) * (bn + 4);
    const size_t size_C = ldc * (bn + 4);

    ba = (float*)aligned_alloc(32, size_ba * sizeof(float));
    bb = (float*)aligned_alloc(32, size_bb * sizeof(float));
    C = (float*)aligned_alloc(32, size_C * sizeof(float));

    if (!ba || !bb || !C) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    for (size_t idx = 0; idx < size_ba; idx++) {
        ba[idx] = (float)(rand() % 100) / 100.0f;
    }
    for (size_t idx = 0; idx < size_bb; idx++) {
        bb[idx] = (float)(rand() % 100) / 100.0f;
    }
    for (size_t idx = 0; idx < size_C; idx++) {
        C[idx] = (float)(rand() % 100) / 100.0f;
    }

    ptrba = ba;
    ptrbb = bb;
}