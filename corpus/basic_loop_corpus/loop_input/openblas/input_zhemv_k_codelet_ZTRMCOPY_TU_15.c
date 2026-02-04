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
    // Allocate matrix 'a' of size m x m, column-major layout
    a = (float*)aligned_alloc(64, m * lda * sizeof(float));
    
    // Allocate b1 and b2: each as block matrices of size (m x m), but accessed in 4x4 blocks
    b1 = (float*)aligned_alloc(64, m * m * sizeof(float));
    b2 = (float*)aligned_alloc(64, m * m * sizeof(float));

    // Initialize all matrix elements to prevent undefined behavior
    for (int i = 0; i < m * lda; i++) {
        ((float*)a)[i] = 1.0f + (i & 1);
    }
    for (int i = 0; i < m * m; i++) {
        b1[i] = 0.0f;
        b2[i] = 0.0f;
    }

    // Ensure m is even for predictable behavior; if not, round down would be needed
    // But we set m = 1024 which is divisible by 2 and safe
}