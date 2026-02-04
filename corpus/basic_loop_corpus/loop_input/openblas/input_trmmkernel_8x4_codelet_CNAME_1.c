#include <stdio.h>
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
    int total_size_a = bm * bk;
    int total_size_b = bk * bn * 2; 
    int total_size_c = bm * ldc;

    ba = (float*)aligned_alloc(32, total_size_a * sizeof(float));
    bb = (float*)aligned_alloc(32, total_size_b * sizeof(float));
    C = (float*)aligned_alloc(32, total_size_c * sizeof(float));

    for (int i = 0; i < total_size_a; i++) {
        ba[i] = (float)((i % 100) * 0.01f);
    }
    for (int i = 0; i < total_size_b; i++) {
        bb[i] = (float)((i % 100) * 0.02f);
    }
    for (int i = 0; i < total_size_c; i++) {
        C[i] = 0.0f;
    }

    off = 0;
}