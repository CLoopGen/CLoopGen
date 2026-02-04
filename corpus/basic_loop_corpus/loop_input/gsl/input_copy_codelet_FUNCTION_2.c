#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

size_t M;
size_t N;
size_t i;
size_t j;

void init_vars() {
    // Set problem size to achieve approximately 0.01 seconds runtime
    // The loop runs for sum_{i=1}^{M-1} min(i, N) iterations
    // To get significant runtime without being too large, set M and N in the range of thousands

    // Empirical tuning: M = 8000, N = 8000 gives roughly O(32M) inner loop iterations,
    // which on a modern CPU (~1e9 ops/sec) takes ~0.01–0.03 seconds depending on optimization
    M = 8000;
    N = 8000;
}