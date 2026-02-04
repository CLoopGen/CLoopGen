#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <time.h>

int Alphabet_size;
float *vec;
int q;
float mix[200];

void init_vars() {
    // Set Alphabet_size to ensure memory transfer takes ~0.01 seconds
    // Assuming modern CPU can handle ~1-10 GB/s for memory copy; target 10-100 MB/s => use ~1-2 MB data
    // But note: mix array is fixed at 200 elements, so we cannot exceed that in the loop.
    // Therefore, we must set Alphabet_size <= 200 to prevent out-of-bounds access.

    Alphabet_size = 200;  // Maximum safe value due to mix[200]

    // Allocate and initialize vec with Alphabet_size elements
    vec = (float*)malloc(Alphabet_size * sizeof(float));
    if (!vec) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }

    // Initialize vec with sample data
    for (int i = 0; i < Alphabet_size; i++) {
        vec[i] = (float)(i + 1) * 0.5f;
    }

    // Initialize mix to zero to have defined state before any use
    for (int i = 0; i < 200; i++) {
        mix[i] = 0.0f;
    }

    // Initialize scalar variables
    q = 0;
}