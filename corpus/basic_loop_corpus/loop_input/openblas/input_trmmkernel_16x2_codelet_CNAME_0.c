#include <stdio.h>
#include <stdlib.h>

typedef long BLASLONG;

BLASLONG bm = 128;
BLASLONG bn = 128;
BLASLONG bk = 64;
float alpha = 1.1f;
float *ba;
float *bb;
float *C;
BLASLONG ldc = 128;
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
float res0_8;
float res0_9;
float res0_10;
float res0_11;
float res0_12;
float res0_13;
float res0_14;
float res0_15;
float res1_0;
float res1_1;
float res1_2;
float res1_3;
float res1_4;
float res1_5;
float res1_6;
float res1_7;
float res1_8;
float res1_9;
float res1_10;
float res1_11;
float res1_12;
float res1_13;
float res1_14;
float res1_15;
float a0;
float a1;
float b0;
float b1;
BLASLONG off = 0;
BLASLONG temp;

void init_vars() {
    size_t ba_size = bm * bk * sizeof(float);
    size_t bb_size = bk * bn * sizeof(float);
    size_t c_size = ldc * bn * sizeof(float);

    ba = (float*)aligned_alloc(64, ba_size);
    bb = (float*)aligned_alloc(64, bb_size);
    C = (float*)aligned_alloc(64, c_size);

    if (!ba || !bb || !C) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    for (size_t idx = 0; idx < bm * bk; idx++) {
        ba[idx] = (float)(idx % 128) / 128.0f;
    }
    for (size_t idx = 0; idx < bk * bn; idx++) {
        bb[idx] = (float)((idx + 1) % 97) / 97.0f;
    }
    for (size_t idx = 0; idx < ldc * bn; idx++) {
        C[idx] = 0.0f;
    }
}