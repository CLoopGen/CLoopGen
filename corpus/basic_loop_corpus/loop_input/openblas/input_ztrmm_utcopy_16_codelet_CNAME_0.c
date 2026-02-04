#include <stdio.h>

typedef long BLASLONG;

BLASLONG lda;
float *b;
BLASLONG ii;
float *a01;

#define DATA_SIZE (64 * 1024 * 1024) // ~64MB of float data
#define A01_ROWS 16
#define A01_COLS 32
#define TOTAL_ELEMENTS (A01_ROWS * A01_COLS)

static float a01_data[TOTAL_ELEMENTS];
static float b_data[DATA_SIZE / sizeof(float)];

void init_vars() {
    lda = 32;
    ii = 0;

    // Initialize a01 to point to the start of a01_data
    a01 = a01_data;

    // Initialize b to point to the start of b_data
    b = b_data;

    // Ensure we don't overflow b_data: the loop runs 16 times, each time writing 32 elements
    // So total written: 16 * 32 = 512 floats -> well within bounds

    // Initialize input data to prevent undefined behavior
    for (int i = 0; i < TOTAL_ELEMENTS; i++) {
        a01_data[i] = 1.0f + (float)i;
    }
}