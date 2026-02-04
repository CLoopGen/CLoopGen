#include <stdio.h>
#include <stdlib.h>

typedef long BLASLONG;

BLASLONG rows = 512;
BLASLONG cols = 512;
float alpha_r = 1.5f;
float alpha_i = 0.8f;
float *a;
BLASLONG lda = 1024;
BLASLONG i;
BLASLONG j;
BLASLONG ia;
BLASLONG ib = 0;
float *aptr;
float *bptr;
float t0;
float t1;

void init_vars() {
    a = (float*)calloc(lda * rows, sizeof(float));
    aptr = a;
}