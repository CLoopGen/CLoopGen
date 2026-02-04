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
float *a05;
float *a06;
float *a07;
float *a08;

#define TOTAL_DATA_SIZE (128 << 20)  // 128 MB target
#define VECTOR_LENGTH 16
#define UNROLL_FACTOR 16

static float *b_data;
static float *a_data;

void init_vars() {
    // Each iteration accesses 16 elements from a01 and writes 16 to b
    // We unroll by 16, so each column block is 16 rows tall
    BLASLONG rows_per_block = VECTOR_LENGTH;
    BLASLONG blocks = TOTAL_DATA_SIZE / (rows_per_block * sizeof(float));
    
    // Ensure at least one block
    if (blocks == 0) blocks = 1;
    
    // Total columns must be at least as many as the loop index i
    i = blocks > 10000 ? 10000 : blocks;
    
    // Allocate b buffer: each iteration writes 16 floats
    b_data = (float*)__builtin_malloc(i * VECTOR_LENGTH * sizeof(float));
    
    // Allocate a matrix: 8 columns (a01..a08), each with i*16 rows
    // But we store it as a contiguous block for simplicity
    BLASLONG a_total_elements = i * VECTOR_LENGTH * 8;
    a_data = (float*)__builtin_malloc(a_total_elements * sizeof(float));
    
    // Initialize pointers
    b = b_data;
    a01 = a_data;
    a02 = a01 + i * VECTOR_LENGTH;
    a03 = a02 + i * VECTOR_LENGTH;
    a04 = a03 + i * VECTOR_LENGTH;
    a05 = a04 + i * VECTOR_LENGTH;
    a06 = a05 + i * VECTOR_LENGTH;
    a07 = a06 + i * VECTOR_LENGTH;
    a08 = a07 + i * VECTOR_LENGTH;
    
    // Set lda to 16 (row stride)
    lda = VECTOR_LENGTH;
    
    // Initialize all data to non-zero to avoid undefined behavior in computations
    for (BLASLONG k = 0; k < i * VECTOR_LENGTH * 8; k++) {
        a_data[k] = (float)(k & 0xFF);
    }
    for (BLASLONG k = 0; k < i * VECTOR_LENGTH; k++) {
        b_data[k] = 0.0f;
    }
}