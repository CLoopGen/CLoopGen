#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
float a0;
float a1;
float b0;
BLASLONG off = 0;
BLASLONG temp;

void init_vars() {
    // Allocate memory based on typical performance target (~0.01s)
    // Matrix A: bm x bk -> 256 x 256 floats
    // Matrix B: bk x bn -> 256 x 1 floats
    // Matrix C: bm x bn (with leading dimension ldc) -> 256 x 1, padded to ldc
    size_t size_ba = bm * bk * sizeof(float);
    size_t size_bb = bk * bn * sizeof(float);
    size_t size_c = bm * ldc * sizeof(float); // ldc may be >= bn

    ba = (float*)aligned_alloc(64, size_ba);
    bb = (float*)aligned_alloc(64, size_bb);
    C = (float*)aligned_alloc(64, size_c);

    if (!ba || !bb || !C) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    // Initialize all arrays with known values to avoid undefined behavior
    for (size_t idx = 0; idx < bm * bk; idx++) {
        ba[idx] = (float)(idx % 100) * 0.01f;
    }
    for (size_t idx = 0; idx < bk * bn; idx++) {
        bb[idx] = (float)(idx % 100) * 0.02f;
    }
    for (size_t idx = 0; idx < bm * ldc; idx++) {
        C[idx] = 0.0f;
    }

    // Reset pointers used in loop
    ptrba = ba;
    ptrbb = bb;
    C0 = C;
}