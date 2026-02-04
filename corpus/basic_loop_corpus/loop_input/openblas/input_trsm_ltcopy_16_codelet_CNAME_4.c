#include <stdio.h>

typedef long BLASLONG;

BLASLONG m;
BLASLONG lda;
float *b;
BLASLONG i;
BLASLONG ii;
BLASLONG jj;
float *a1;

#define DATA_SIZE (64 << 20) // ~64MB of data

static float *b_data;
static float *a1_data;

void init_vars() {
    // Allocate memory for b and a1 arrays
    b_data = (float*)__builtin_malloc(DATA_SIZE);
    a1_data = (float*)__builtin_malloc(DATA_SIZE);

    // Initialize loop parameters
    m = 8192;          // Number of iterations
    lda = 1024;        // Leading dimension for a1 stride
    ii = 0;
    jj = 0;
    
    // Ensure valid pointer initializations
    b = b_data;
    a1 = a1_data;

    // Initialize array contents to avoid division by zero or undefined behavior
    for (BLASLONG k = 0; k < DATA_SIZE / sizeof(float); k++) {
        a1_data[k] = 2.0f; // Non-zero to ensure safe division
        b_data[k] = 0.0f;
    }
}