#include <stdio.h>
#include <stdlib.h>

typedef long BLASLONG;

BLASLONG lda = 16;

float *buffer;
float *a1;
float *a3;
float *a5;
float *a7;
float *b1;
float *b2;
float *b3;
float *b4;
float *b5;
float *b6;
float *b7;
float *b8;

float A1, A2, A3, A4, A5, A6, A7, A8;
float A9, A10, A11, A12, A13, A14, A15, A16;
float B1, B2, B3, B4, B5, B6, B7, B8;
float B9, B10, B11, B12, B13, B14, B15, B16;

void init_vars() {
    const int total_size = 1 << 24; // ~16MB of data to target ~0.01s runtime
    const int num_iterations = total_size / (16 * sizeof(float)) / 2; // 2 passes per loop iteration

    float *data_pool = (float *)aligned_alloc(64, total_size);
    if (!data_pool) exit(1);

    buffer = data_pool;
    a1 = data_pool + 16;
    a3 = a1 + 4;
    a5 = a3 + 4;
    a7 = a5 + 4;
    b1 = a7 + 4;
    b2 = b1 + 4 * lda * num_iterations;
    b3 = b2 + 4 * lda * num_iterations;
    b4 = b3 + 4 * lda * num_iterations;
    b5 = b4 + 4 * lda * num_iterations;
    b6 = b5 + 4 * lda * num_iterations;
    b7 = b6 + 4 * lda * num_iterations;
    b8 = b7 + 4 * lda * num_iterations;

    // Ensure no overlap that breaks assumptions unless intended
    for (int i = 0; i < total_size / sizeof(float); ++i) {
        data_pool[i] = (float)(i & 255) / 2.0f;
    }

    // Set initial pointer values so first access is in bounds
    b1 = data_pool + 16 * 1;
    b2 = data_pool + 16 * 2;
    b3 = data_pool + 16 * 3;
    b4 = data_pool + 16 * 4;
    b5 = data_pool + 16 * 5;
    b6 = data_pool + 16 * 6;
    b7 = data_pool + 16 * 7;
    b8 = data_pool + 16 * 8;
    a1 = data_pool + 16 * 9;
    a3 = a1 + 4;
    a5 = a3 + 4;
    a7 = a5 + 4;
    buffer = data_pool + 16 * 10;

    // Initialize scalars to avoid undefined behavior
    A1 = A2 = A3 = A4 = A5 = A6 = A7 = A8 = 0.0f;
    A9 = A10 = A11 = A12 = A13 = A14 = A15 = A16 = 0.0f;
    B1 = B2 = B3 = B4 = B5 = B6 = B7 = B8 = 0.0f;
    B9 = B10 = B11 = B12 = B13 = B14 = B15 = B16 = 0.0f;
}