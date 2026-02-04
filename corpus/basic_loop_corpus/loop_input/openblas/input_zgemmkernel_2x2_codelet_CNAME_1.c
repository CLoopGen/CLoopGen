#include <stdio.h>
#include <stdlib.h>

typedef long BLASLONG;

BLASLONG bm = 256;
BLASLONG bn = 256;
BLASLONG bk = 256;
float alphar = 1.5f;
float alphai = 0.8f;

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
float res0;
float res1;
float res2;
float res3;
float load0;
float load1;
float load2;
float load3;

void init_vars() {
    const size_t size_a = (bm + 2) * bk * 2; 
    const size_t size_b = (bn + 1) * bk * 2; 
    const size_t size_c = (bm + 2) * (bn + 1) * 2;

    ba = (float*)aligned_alloc(32, size_a * sizeof(float));
    bb = (float*)aligned_alloc(32, size_b * sizeof(float));
    C  = (float*)aligned_alloc(32, size_c * sizeof(float));

    for (size_t idx = 0; idx < size_a; idx++) {
        ba[idx] = (float)(idx % 100) / 100.0f;
    }
    for (size_t idx = 0; idx < size_b; idx++) {
        bb[idx] = (float)(idx % 100) / 100.0f;
    }
    for (size_t idx = 0; idx < size_c; idx++) {
        C[idx] = (float)(idx % 100) / 100.0f;
    }

    i = 0;
    j = 0;
    k = 0;

    C0 = C;
    ptrba = ba;
    ptrbb = bb;
    res0 = 0.0f;
    res1 = 0.0f;
    res2 = 0.0f;
    res3 = 0.0f;
    load0 = 0.0f;
    load1 = 0.0f;
    load2 = 0.0f;
    load3 = 0.0f;
}