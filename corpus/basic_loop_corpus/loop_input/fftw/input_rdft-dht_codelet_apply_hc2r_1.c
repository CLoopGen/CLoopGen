#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <time.h>

typedef double R;
typedef ptrdiff_t INT;
typedef R E;

R *I = NULL;
INT is = 1;
INT i = 0;
INT n = 0;

void init_vars() {
    const size_t target_time_ns = 10000000; // 10 ms in nanoseconds
    const long double clock_freq_guess = 3e9; // Assume 3 GHz typical CPU
    const INT ops_per_iter = 4; // Rough estimate of memory operations per iteration

    // Estimate total iterations to achieve ~10ms runtime
    // Each iteration does 4 memory accesses (2 loads, 2 stores), two arithmetic ops
    // We'll use array size such that the loop runs enough iterations
    // Loop runs for i from 1 to (n-1)/2, so about n/2 iterations
    // We choose n such that cache effects are present but not dominating
    // Start with 64M elements -> loop runs ~32M times, each doing 4 memory ops -> ~128M ops
    // At 3GHz, 128M ops ~ 42ms -> too high. Scale down.

    // Try n = 16M -> loop runs ~8M times -> ~32M memory ops -> ~10.6ms -> close enough
    n = 16 * 1024 * 1024; // 16M elements

    // Allocate array I with n elements
    I = (R*)aligned_alloc(sizeof(R), n * sizeof(R));
    if (!I) {
        exit(1);
    }

    // Initialize array with non-zero values to ensure meaningful computation
    for (INT j = 0; j < n; ++j) {
        I[j] = (R)(j % 1000) + 1.0;
    }

    // Set stride is to 1 (common case)
    is = 1;

    // Ensure i is initialized to 0 before loop starts (loop will set it to 1)
    i = 0;
}