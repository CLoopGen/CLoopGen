#include <stdio.h>

typedef long BLASLONG;

BLASLONG lda;
float *b;
BLASLONG ii;
float *a01;

#define DATA_SIZE (64 * 1024 * 1024) // ~64 MB of float data
#define A_ROWS 16
#define A_COLS 32
#define TOTAL_B_SIZE (A_ROWS * A_COLS)

static float a_data[A_ROWS][A_COLS];
static float b_data[TOTAL_B_SIZE];

void init_vars() {
    lda = 32;
    
    // Initialize a01 to point to the first row of a_data
    a01 = &a_data[0][0];
    
    // Initialize b to point to the start of b_data
    b = &b_data[0];
    
    // Initialize a_data with non-zero values to make it easier to track
    for (int i = 0; i < A_ROWS; i++) {
        for (int j = 0; j < A_COLS; j++) {
            a_data[i][j] = (float)(i * A_COLS + j + 1);
        }
    }
    
    // Zero out b_data initially
    for (int i = 0; i < TOTAL_B_SIZE; i++) {
        b_data[i] = 0.0f;
    }
}