#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef long BLASLONG;

BLASLONG bm = 512;
BLASLONG bn = 512;
BLASLONG bk = 512;
float alpha = 1.1f;
float *ba;
float *bb;
float *C;
BLASLONG ldc = 512;
BLASLONG i;
BLASLONG j;
BLASLONG k;
float *C0;
float *C1;
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
float load4;
float load5;
float load6;
float load7;

void init_vars() {
    const size_t ba_size = (bm + 8) * (bk + 8);
    const size_t bb_size = (bk + 8) * (bn + 8);
    const size_t c_size = (ldc + 8) * (bn + 8);

    ba = (float*)aligned_alloc(32, ba_size * sizeof(float));
    bb = (float*)aligned_alloc(32, bb_size * sizeof(float));
    C = (float*)aligned_alloc(32, c_size * sizeof(float));

    if (!ba || !bb || !C) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    for (size_t idx = 0; idx < ba_size; ++idx) {
        ba[idx] = (float)(idx % 100) * 0.01f;
    }
    for (size_t idx = 0; idx < bb_size; ++idx) {
        bb[idx] = (float)(idx % 100) * 0.02f;
    }
    for (size_t idx = 0; idx < c_size; ++idx) {
        C[idx] = (float)(idx % 100) * 0.03f;
    }
}