#include <stdio.h>
#include <stdlib.h>

typedef long BLASLONG;

BLASLONG bm = 1024;
BLASLONG bn = 1024;
BLASLONG bk = 1024;
float alpha = 1.5f;
float *ba;
float *bb;
float *C;
BLASLONG ldc = 1024;
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
BLASLONG off = 0;
BLASLONG temp;

static float *alloc_float_array(size_t size) {
    float *ptr = (float *)malloc(size * sizeof(float));
    if (!ptr) {
        exit(1);
    }
    return ptr;
}

void init_vars() {
    size_t size_a = (size_t)bm * bk;
    size_t size_b = (size_t)bk * bn * 2;
    size_t size_c = (size_t)ldc * bn;

    ba = alloc_float_array(size_a);
    bb = alloc_float_array(size_b);
    C = alloc_float_array(size_c);

    for (size_t idx = 0; idx < size_a; idx++) {
        ba[idx] = 1.0f;
    }
    for (size_t idx = 0; idx < size_b; idx++) {
        bb[idx] = 1.0f;
    }
    for (size_t idx = 0; idx < size_c; idx++) {
        C[idx] = 0.0f;
    }
}