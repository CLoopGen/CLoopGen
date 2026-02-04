#include <stdio.h>
#include <stdlib.h>

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
float a12;
float a21;
float a22;

void init_vars() {
    // Allocate matrix 'a' of size m x m, row-major order assumed via lda
    a = (float*)aligned_alloc(64, sizeof(float) * m * lda);
    
    // Allocate b1 and b2 as matrices of size m x m
    b1 = (float*)aligned_alloc(64, sizeof(float) * m * m);
    b2 = (float*)aligned_alloc(64, sizeof(float) * m * m);

    // Initialize all matrix elements to known values to avoid undefined behavior
    for (int i = 0; i < m * lda; i++) {
        a[i] = (float)(i + 1);
    }
    for (int i = 0; i < m * m; i++) {
        b1[i] = 0.0f;
        b2[i] = 0.0f;
    }

    // Ensure initial pointers are NULL to prevent accidental use before assignment
    aa1 = NULL;
    aa2 = NULL;
    bb1 = NULL;
    bb2 = NULL;
    cc1 = NULL;
    cc2 = NULL;
}