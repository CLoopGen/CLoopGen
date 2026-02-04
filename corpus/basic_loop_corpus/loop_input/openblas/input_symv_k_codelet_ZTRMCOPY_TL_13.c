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
    // Allocate matrix 'a' of size at least m x (lda) but with extra padding for safe access
    a = (float*)calloc(m * (lda + 8) + 32, sizeof(float));
    if (!a) exit(1);

    // Allocate b1 and b2: each needs space for m * m elements with padding
    b1 = (float*)calloc(m * m + 8 * m + 32, sizeof(float));
    b2 = (float*)calloc(m * m + 8 * m + 32, sizeof(float));
    if (!b1 || !b2) exit(1);

    // Initialize all output arrays to zero to avoid undefined behavior
    memset(a, 0, (m * (lda + 8)) * sizeof(float));
    memset(b1, 0, (m * m + 8 * m) * sizeof(float));
    memset(b2, 0, (m * m + 8 * m) * sizeof(float));

    // Ensure that during the loop, we won't access out-of-bounds
    // The loop accesses up to a + 2*lda + 4 + ... with increments
    // We already padded a sufficiently.

    // Set initial values for pointers to prevent null dereference
    aa1 = a;
    aa2 = a + lda;
    bb1 = b1;
    bb2 = b1 + 2 * m;
    cc1 = b2;
    cc2 = b2 + 2 * m;
}