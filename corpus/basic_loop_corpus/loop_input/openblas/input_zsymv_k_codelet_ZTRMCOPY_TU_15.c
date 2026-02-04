#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef long BLASLONG;

BLASLONG m = 1024;
float *a;
BLASLONG lda = 1024;
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
    // Allocate matrix 'a' of size m x (lda) but we access up to row offset 2*lda and column offset 3
    a = (float*)aligned_alloc(64, sizeof(float) * lda * (m + 4));
    if (!a) exit(1);
    memset(a, 0, sizeof(float) * lda * (m + 4));

    // b1 and b2 are used with offsets involving m and 4*m, so allocate sufficient space
    // Total size needed: at least (m + 4) * 4 * sizeof(float) for each block
    b1 = (float*)aligned_alloc(64, sizeof(float) * m * (m + 8));
    if (!b1) exit(1);
    memset(b1, 0, sizeof(float) * m * (m + 8));

    b2 = (float*)aligned_alloc(64, sizeof(float) * m * (m + 8));
    if (!b2) exit(1);
    memset(b2, 0, sizeof(float) * m * (m + 8));

    // Initialize pointers that will be used inside loop
    aa1 = a;
    aa2 = a + lda;
    bb1 = b1;
    bb2 = b1 + 2 * m;
    cc1 = b2;
    cc2 = b2 + 2 * m;
}