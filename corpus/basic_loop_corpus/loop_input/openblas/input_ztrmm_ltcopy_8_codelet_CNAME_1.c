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

#define TOTAL_DATA_SIZE (128 << 20)  // 128 MB target data size
#define VECTOR_LENGTH 16
#define OUTER_LOOPS 10000

static float static_b_data[OUTER_LOOPS * VECTOR_LENGTH];
static float static_a_data[8][OUTER_LOOPS * VECTOR_LENGTH];

void init_vars() {
    // Initialize loop count
    i = OUTER_LOOPS;
    
    // Set leading dimension to vector length for stride access
    lda = VECTOR_LENGTH;
    
    // Initialize b to point to static buffer
    b = static_b_data;
    
    // Initialize a01-a08 to point to respective blocks
    a01 = static_a_data[0];
    a02 = static_a_data[1];
    a03 = static_a_data[2];
    a04 = static_a_data[3];
    a05 = static_a_data[4];
    a06 = static_a_data[5];
    a07 = static_a_data[6];
    a08 = static_a_data[7];
    
    // Initialize all arrays with non-zero values to avoid zero-filled optimization
    for (int j = 0; j < 8; j++) {
        for (int k = 0; k < OUTER_LOOPS * VECTOR_LENGTH; k++) {
            static_a_data[j][k] = (float)(j * 0.1f + k * 0.01f);
        }
    }
    
    for (int k = 0; k < OUTER_LOOPS * VECTOR_LENGTH; k++) {
        static_b_data[k] = 0.0f;
    }
}