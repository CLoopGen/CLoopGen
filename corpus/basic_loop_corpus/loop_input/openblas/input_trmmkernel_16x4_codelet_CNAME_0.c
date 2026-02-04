#include <stdio.h>
#include <stdlib.h>

typedef long BLASLONG;

BLASLONG bm = 256;
BLASLONG bn = 256;
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
float *C2;
float *C3;
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
float res2_0;
float res2_1;
float res2_2;
float res2_3;
float res2_4;
float res2_5;
float res2_6;
float res2_7;
float res2_8;
float res2_9;
float res2_10;
float res2_11;
float res2_12;
float res2_13;
float res2_14;
float res2_15;
float res3_0;
float res3_1;
float res3_2;
float res3_3;
float res3_4;
float res3_5;
float res3_6;
float res3_7;
float res3_8;
float res3_9;
float res3_10;
float res3_11;
float res3_12;
float res3_13;
float res3_14;
float res3_15;
float a0;
float a1;
float b0;
float b1;
float b2;
float b3;
BLASLONG off = 0;
BLASLONG temp;

void init_vars() {
    const size_t ba_size = bm * bk * sizeof(float);
    const size_t bb_size = bk * bn * sizeof(float);
    const size_t c_size = ldc * bn * sizeof(float);

    ba = (float*)aligned_alloc(64, ba_size);
    bb = (float*)aligned_alloc(64, bb_size);
    C = (float*)aligned_alloc(64, c_size);

    if (!ba || !bb || !C) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    for (size_t i = 0; i < bm * bk; i++) {
        ba[i] = (float)((i % 100) * 0.01f);
    }
    for (size_t i = 0; i < bk * bn; i++) {
        bb[i] = (float)((i % 100) * 0.02f);
    }
    for (size_t i = 0; i < ldc * bn; i++) {
        C[i] = (float)((i % 100) * 0.03f);
    }

    i = 0;
    j = 0;
    k = 0;
    ptrba = ba;
    ptrbb = bb;
    C0 = C;
    C1 = C + ldc;
    C2 = C + 2 * ldc;
    C3 = C + 3 * ldc;
}