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
    // Allocate matrix 'a' with size m x (lda), padded for safe access
    a = (float*)aligned_alloc(32, sizeof(float) * m * lda);
    
    // Allocate b1 and b2 as large arrays to simulate output buffers
    // Total size ~128MB to ensure meaningful runtime (~0.01s on modern CPU)
    BLASLONG b_size = (1 << 25); // ~134M floats, ~512MB total for both
    b1 = (float*)aligned_alloc(32, sizeof(float) * b_size);
    b2 = (float*)aligned_alloc(32, sizeof(float) * b_size);

    // Initialize all pointers to avoid undefined behavior
    aa1 = aa2 = NULL;
    bb1 = bb2 = NULL;
    cc1 = cc2 = NULL;

    // Initialize input matrix 'a' with non-zero values for realistic use
    for (BLASLONG i = 0; i < m; i++) {
        for (BLASLONG j = 0; j < lda; j++) {
            a[i * lda + j] = (float)((i + 1) * 0.01f + (j + 1) * 0.001f);
        }
    }

    // Initialize b1 and b2 areas to zero to make writes visible
    for (BLASLONG i = 0; i < b_size; i++) {
        b1[i] = 0.0f;
        b2[i] = 0.0f;
    }

    // Ensure m is at least 2 so loop runs meaningfully
    if (m < 2) m = 2;

    // Clamp m to reasonable bound based on allocated space
    // The algorithm uses up to 4*lda stride and 4*m offsets, so we limit growth
    BLASLONG max_safe_m = 4096;
    if (m > max_safe_m) m = max_safe_m;
}