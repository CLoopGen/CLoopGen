#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

unsigned int k;
unsigned int opt_order;
int32_t *quant_cof;
int add_base;

void init_vars() {
    // Set parameters to ensure loop runs with sufficient workload (~0.01 sec)
    // Assume opt_order around 10M to 20M gives suitable runtime
    opt_order = 16000000;  // 16 million iterations typical for ~0.01s

    // Allocate quant_cof array with size opt_order to prevent out-of-bounds access
    quant_cof = (int32_t*)aligned_alloc(32, opt_order * sizeof(int32_t));
    if (!quant_cof) {
        exit(1);
    }

    // Initialize array elements to non-zero predictable values for computation
    for (unsigned int i = 0; i < opt_order; i++) {
        quant_cof[i] = (int32_t)(i & 0xFFFF);
    }

    // Initialize add_base to a small constant value
    add_base = 1;

    // Ensure k starts at 2 as per loop initialization
    k = 2;
}