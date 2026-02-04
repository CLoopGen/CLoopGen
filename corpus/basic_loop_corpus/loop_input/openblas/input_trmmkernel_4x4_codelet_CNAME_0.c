#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef long BLASLONG;

BLASLONG bm = 256;
BLASLONG bn = 256;
BLASLONG bk = 128;
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
    size_t ba_size = (size_t)bm * bk * sizeof(float);
    size_t bb_size = (size_t)bk * bn * sizeof(float);
    size_t c_size = (size_t)ldc * bn * sizeof(float);

    ba = (float*)aligned_alloc(32, ba_size);
    bb = (float*)aligned_alloc(32, bb_size);
    C = (float*)aligned_alloc(32, c_size);

    if (!ba || !bb || !C) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    for (size_t idx = 0; idx < ba_size / sizeof(float); idx++) {
        ba[idx] = (float)(drand48() * 2.0 - 1.0);
    }
    for (size_t idx = 0; idx < bb_size / sizeof(float); idx++) {
        bb[idx] = (float)(drand48() * 2.0 - 1.0);
    }
    for (size_t idx = 0; idx < c_size / sizeof(float); idx++) {
        C[idx] = (float)(drand48() * 2.0 - 1.0);
    }

    srand((unsigned int)time(NULL));
}