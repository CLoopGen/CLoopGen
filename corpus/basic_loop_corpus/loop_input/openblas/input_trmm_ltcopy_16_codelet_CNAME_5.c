#include <stdio.h>

typedef long BLASLONG;

BLASLONG lda;
float *b;
BLASLONG i;
BLASLONG ii;
float *a01;
float *a02;
float *a03;
float *a04;

#define DATA_SIZE_MB 64
#define TOTAL_FLOATS (DATA_SIZE_MB * 1024 * 1024 / sizeof(float))

static float global_data[TOTAL_FLOATS];
static float b_buffer[TOTAL_FLOATS];

void init_vars() {
    // Set problem size to achieve roughly 0.01 seconds runtime
    // Assuming cache-friendly access and modern CPU (several GB/s bandwidth)
    lda = 1024;  // Typical leading dimension for matrix
    i = (TOTAL_FLOATS / 4) / (4 * lda);  // Ensure we have enough data for i iterations
    
    if (i == 0) i = 1000;  // Fallback minimum iterations
    
    // Make sure we don't exceed buffer bounds
    while (i * lda > TOTAL_FLOATS / 4) {
        i--;
    }
    
    // Initialize pointers into global_data with appropriate spacing
    a01 = global_data;
    a02 = global_data + lda;
    a03 = global_data + 2 * lda;
    a04 = global_data + 3 * lda;
    
    // Initialize b to point to buffer
    b = b_buffer;
    
    // Initialize input data to prevent undefined behavior
    for (int j = 0; j < TOTAL_FLOATS; j++) {
        global_data[j] = (float)(j % 100);
    }
    
    for (int j = 0; j < TOTAL_FLOATS; j++) {
        b_buffer[j] = 0.0f;
    }
}