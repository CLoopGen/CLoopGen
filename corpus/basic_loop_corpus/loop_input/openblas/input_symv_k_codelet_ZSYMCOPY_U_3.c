#include <stdlib.h>
#include <string.h>

typedef long BLASLONG;

BLASLONG m = 256;
float *a;
BLASLONG lda = 512;
BLASLONG is;
BLASLONG js;
float *aa1;
float *aa2;
float *b1;
float *b2;
float *bb1;
float *bb2;
float *cc1;
float *cc2;
float a11;
float a21;
float a31;
float a41;
float a12;
float a22;
float a32;
float a42;

void init_vars() {
    a = (float*)aligned_alloc(64, sizeof(float) * lda * m);
    b1 = (float*)aligned_alloc(64, sizeof(float) * m * m * 2);
    b2 = (float*)aligned_alloc(64, sizeof(float) * m * m * 2);

    if (!a || !b1 || !b2) {
        exit(1);
    }

    for (BLASLONG i = 0; i < lda * m; i++) {
        a[i] = (float)(i + 1);
    }
    for (BLASLONG i = 0; i < m * m * 2; i++) {
        b1[i] = 0.0f;
        b2[i] = 0.0f;
    }
}