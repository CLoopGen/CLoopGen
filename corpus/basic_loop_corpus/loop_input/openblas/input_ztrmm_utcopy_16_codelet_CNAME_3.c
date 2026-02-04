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

static float *b_data;
static float *a_data;

void init_vars() {
    const BLASLONG vector_size = 16;
    const BLASLONG num_vectors = 8;
    const BLASLONG total_elements = 1000000; // ~4MB of data, adjust for ~0.01s runtime

    lda = 16; // stride matches vector size
    i = total_elements / vector_size;

    // Allocate aligned memory to prevent issues and improve performance
    b_data = (float*)__builtin_malloc(total_elements * sizeof(float));
    a_data = (float*)__builtin_malloc(total_elements * num_vectors * sizeof(float));

    // Initialize pointers
    b = b_data;
    a01 = a_data;
    a02 = a01 + total_elements;
    a03 = a02 + total_elements;
    a04 = a03 + total_elements;
    a05 = a04 + total_elements;
    a06 = a05 + total_elements;
    a07 = a06 + total_elements;
    a08 = a07 + total_elements;

    // Initialize input data to avoid undefined behavior
    for (BLASLONG k = 0; k < total_elements * num_vectors; k++) {
        a_data[k] = (float)(k % 128);
    }
    for (BLASLONG k = 0; k < total_elements; k++) {
        b_data[k] = 0.0f;
    }
}