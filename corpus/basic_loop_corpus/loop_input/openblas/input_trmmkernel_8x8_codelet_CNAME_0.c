#include <stdlib.h>
#include <string.h>

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
float res2_0;
float res2_1;
float res2_2;
float res2_3;
float res2_4;
float res2_5;
float res2_6;
float res2_7;
float res3_0;
float res3_1;
float res3_2;
float res3_3;
float res3_4;
float res3_5;
float res3_6;
float res3_7;
float res4_0;
float res4_1;
float res4_2;
float res4_3;
float res4_4;
float res4_5;
float res4_6;
float res4_7;
float res5_0;
float res5_1;
float res5_2;
float res5_3;
float res5_4;
float res5_5;
float res5_6;
float res5_7;
float res6_0;
float res6_1;
float res6_2;
float res6_3;
float res6_4;
float res6_5;
float res6_6;
float res6_7;
float res7_0;
float res7_1;
float res7_2;
float res7_3;
float res7_4;
float res7_5;
float res7_6;
float res7_7;
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
BLASLONG off = 0;
BLASLONG temp;

void init_vars() {
    size_t size_a = (size_t)bm * bk * sizeof(float);
    size_t size_b = (size_t)bk * bn * sizeof(float);
    size_t size_c = (size_t)ldc * bn * sizeof(float);

    ba = (float*)aligned_alloc(32, size_a);
    bb = (float*)aligned_alloc(32, size_b);
    C = (float*)aligned_alloc(32, size_c);

    if (!ba || !bb || !C) {
        exit(1);
    }

    for (size_t i = 0; i < bm * bk; i++) {
        ba[i] = (float)(i % 128) / 128.0f;
    }
    for (size_t i = 0; i < bk * bn; i++) {
        bb[i] = (float)((i + 1) % 97) / 97.0f;
    }
    for (size_t i = 0; i < ldc * bn; i++) {
        C[i] = 0.0f;
    }
}