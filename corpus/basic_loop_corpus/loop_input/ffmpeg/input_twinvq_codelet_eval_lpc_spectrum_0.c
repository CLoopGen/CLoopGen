#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <math.h>

#define DATA_SIZE_MB 64
#define TOTAL_ELEMENTS (DATA_SIZE_MB * 1024 * 1024 / sizeof(float))

float *lsp;
int order;
int j;
float p;
float q;
float two_cos_w;

void init_vars() {
    // Allocate lsp array with sufficient size
    lsp = (float*)aligned_alloc(32, TOTAL_ELEMENTS * sizeof(float));
    
    if (!lsp) {
        exit(1);
    }

    // Initialize array elements to valid floating-point values
    for (size_t i = 0; i < TOTAL_ELEMENTS; ++i) {
        lsp[i] = 2.0f * ((float)i / TOTAL_ELEMENTS); // spans [0, 2)
    }

    // Set order to a value that ensures loop runs for significant time
    // Ensure order is even and leaves room for j+3 access
    order = TOTAL_ELEMENTS - 4;
    if (order % 4 != 0) {
        order -= (order % 4);
    }

    // Initialize multiplicative accumulators
    p = 1.0f;
    q = 1.0f;

    // Set two_cos_w to a typical value within expected range of lsp
    two_cos_w = 1.0f;
}