#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

size_t M;
size_t N;
size_t i;
size_t j;

void init_vars() {
    // Estimate data size to achieve ~0.01 seconds runtime
    // The loop has O(M * min(M, N)) iterations. Set M and N such that total operations
    // are on the order of hundreds of millions to a few billion for 10ms on modern CPU.

    // Heuristic: ~1e8 to 1e9 operations in 0.01s => aim for about 5e8 iterations.
    // Let M = 22400, then inner loop runs roughly sum_{i=1}^{M-1} min(i, N)
    // If we set N = M, total iterations ~ M*(M-1)/2 ≈ 22400*22399/2 ≈ 250 million
    // That should be safe within 10ms range.

    M = 22400;
    N = 22400;
}