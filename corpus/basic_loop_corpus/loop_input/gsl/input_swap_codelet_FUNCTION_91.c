#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

size_t size1;
size_t p;

void init_vars() {
    // Assuming a moderate data size to achieve ~0.01s runtime
    // The loop body is empty, so we choose size1 such that the loop overhead takes ~0.01s
    // On a modern CPU, a few hundred million iterations may take ~0.01s depending on clock speed
    // We estimate 100 million iterations ≈ 0.01s
    size1 = 100000000ULL; // 100 million
    p = 0;
}