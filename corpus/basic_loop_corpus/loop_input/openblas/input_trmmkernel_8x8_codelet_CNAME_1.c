#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef long BLASLONG;

BLASLONG bm = 256;
BLASLONG bn = 1024;
BLASLONG bk = 256;
float alpha = 1.1f;
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
    size_t size_ba = (size_t)bk * (size_t)bm * sizeof(float);
    size_t size_bb = (size_t)bk * (size_t)bn * 2 * sizeof(float);
    size_t size_C  = (size_t)ldc * (size_t)bn * 2 * sizeof(float);

    ba = (float*)aligned_alloc(32, size_ba);
    bb = (float*)aligned_alloc(32, size_bb);
    C  = (float*)aligned_alloc(32, size_C);

    if (!ba || !bb || !C) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    for (size_t idx = 0; idx < size_ba / sizeof(float); idx++) {
        ba[idx] = (float)((rand() % 1000) / 100.0);
    }
    for (size_t idx = 0; idx < size_bb / sizeof(float); idx++) {
        bb[idx] = (float)((rand() % 1000) / 100.0);
    }
    for (size_t idx = 0; idx < size_C / sizeof(float); idx++) {
        C[idx] = (float)((rand() % 1000) / 100.0);
    }
}