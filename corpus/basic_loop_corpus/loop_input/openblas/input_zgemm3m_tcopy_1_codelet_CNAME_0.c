#include <stdio.h>

typedef long BLASLONG;

BLASLONG m;
BLASLONG lda;
float *b;
BLASLONG i;
float *a_offset;
float a1;
float a2;

float *b_array;
float *a_array;

void init_vars() {
    // Set problem size to get around 0.01s runtime on modern CPU
    // Each iteration accesses 2 floats from a and writes 1 float to b
    // Aim for ~16M iterations to hit target time (empirically reasonable)
    m = 16000000;
    
    // Set leading dimension greater than stride used in loop (which is 2)
    lda = 4;
    
    // Allocate arrays with proper bounds
    // a_array needs m rows with lda spacing, each accessing +0 and +1
    // so we need at least m*lda elements
    a_array = (float*)__builtin_malloc(m * lda * sizeof(float));
    b_array = (float*)__builtin_malloc(m * sizeof(float));
    
    // Initialize pointers
    a_offset = a_array;
    b = b_array;
    
    // Initialize array data to avoid undefined behavior
    for (BLASLONG j = 0; j < m * lda; j++) {
        a_array[j] = (float)(j % 100) / 10.0f;
    }
    for (BLASLONG j = 0; j < m; j++) {
        b_array[j] = 0.0f;
    }
    
    // Initialize scalars
    a1 = 0.0f;
    a2 = 0.0f;
}