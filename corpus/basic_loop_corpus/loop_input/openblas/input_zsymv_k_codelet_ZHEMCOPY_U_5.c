#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef long BLASLONG;

BLASLONG m;
float *a;
BLASLONG lda;
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
    // Set matrix size to achieve ~0.01s runtime - chosen empirically
    // For typical modern CPU, m=512 provides sufficient workload without excessive memory
    m = 512;
    
    // Leading dimension at least as large as m
    lda = m;
    
    // Allocate arrays with proper sizes to prevent out-of-bounds access
    // Total data processed: m x m matrix 'a'
    a = (float*)aligned_alloc(64, sizeof(float) * lda * m);
    
    // b1 and b2 are used with offsets up to 4*m and written with strides of 4 and 4*m
    // Need to ensure enough space for worst-case access
    b1 = (float*)aligned_alloc(64, sizeof(float) * 4 * m * ((m + 1)/2 + 1));
    b2 = (float*)aligned_alloc(64, sizeof(float) * 4 * m * ((m + 1)/2 + 1));
    
    // Initialize all pointers that are derived from a, b1, b2 inside loop
    // but set them to NULL here since they'll be reassigned in loop
    aa1 = NULL;
    aa2 = NULL;
    bb1 = NULL;
    bb2 = NULL;
    cc1 = NULL;
    cc2 = NULL;
    
    // Initialize scalar variables to zero
    a11 = 0.0f; a21 = 0.0f; a31 = 0.0f; a41 = 0.0f;
    a12 = 0.0f; a22 = 0.0f; a32 = 0.0f; a42 = 0.0f;
    
    // Initialize loop indices
    is = 0;
    js = 0;
    
    // Pre-initialize input matrix 'a' to avoid undefined behavior
    for (BLASLONG i = 0; i < lda * m; i++) {
        a[i] = (float)(i % 100) / 100.0f;
    }
    
    // Initialize output blocks to prevent garbage writes
    memset(b1, 0, sizeof(float) * 4 * m * ((m + 1)/2 + 1));
    memset(b2, 0, sizeof(float) * 4 * m * ((m + 1)/2 + 1));
}