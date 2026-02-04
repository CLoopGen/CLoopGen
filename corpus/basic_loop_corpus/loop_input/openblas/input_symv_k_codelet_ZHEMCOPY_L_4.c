#include <stdio.h>
#include <stdlib.h>

typedef long BLASLONG;

BLASLONG m = 1024;
float *a;
BLASLONG lda = 1028;
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
    // Allocate 'a' as a matrix of size at least (m + 2) x (lda), with padding to prevent overflow
    a = (float*)aligned_alloc(32, sizeof(float) * (m + 4) * (lda + 4));
    b1 = (float*)aligned_alloc(32, sizeof(float) * (m + 4) * (m + 4));
    b2 = (float*)aligned_alloc(32, sizeof(float) * (m + 4) * (m + 4));

    // Initialize all memory to avoid undefined behavior
    for (int i = 0; i < (m + 4) * (lda + 4); i++) {
        ((float*)a)[i] = 1.0f + (i & 15);
    }
    for (int i = 0; i < (m + 4) * (m + 4); i++) {
        ((float*)b1)[i] = 0.0f;
        ((float*)b2)[i] = 0.0f;
    }

    // Ensure m is even or odd consistently — use even base and adjust if needed
    // Here m = 1024 (even) so final "if (m & 1)" block won't run unless we change it
    // But loop logic expects up to m-1, so current setup is safe.
}