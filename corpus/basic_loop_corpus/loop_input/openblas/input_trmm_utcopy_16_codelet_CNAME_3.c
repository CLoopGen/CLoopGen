#include <stdio.h>

typedef long BLASLONG;

BLASLONG lda;
float *b;
BLASLONG i;
BLASLONG ii;
float *a01;

float *original_b_start;
float *original_a01_start;

#define DATA_SIZE_MB 64
#define TOTAL_FLOATS (DATA_SIZE_MB * 1024 * 1024 / sizeof(float))

static float global_data[TOTAL_FLOATS];
static float global_a_data[TOTAL_FLOATS];

void init_vars() {
    // Initialize lda to 8 for stride access
    lda = 8;
    
    // Set problem size: ensure we have enough rows with 8 elements each
    i = (TOTAL_FLOATS / 8) / 2;  // Use half for a, half for b to avoid overlap
    
    // Initialize original pointers
    original_a01_start = global_a_data;
    original_b_start = global_data;
    
    a01 = original_a01_start;
    b = original_b_start;
    
    // Initialize input data to prevent undefined behavior
    for (int j = 0; j < TOTAL_FLOATS; j++) {
        global_data[j] = 1.0f;
        global_a_data[j] = (float)(j + 1);
    }
}