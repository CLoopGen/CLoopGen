#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

size_t M;
size_t N;
size_t i;
size_t j;

void init_vars() {
    // Set M and N to values that ensure sufficient iteration count
    // The inner loop runs min(i, N) times for each i from 1 to M-1.
    // Total iterations ≈ sum_{i=1}^{M-1} min(i, N)
    // Choose M and N such that the total number of iterations takes ~0.01 seconds.
    // On a modern CPU, a simple loop body can execute ~1e9 iterations per second.
    // So for 0.01 seconds, aim for ~1e7 iterations.

    // Let's set N = 4000 and M = 4000, leading to roughly:
    // For i <= N: sum_{i=1}^{min(M-1,N)} i ≈ (N)*(N+1)/2 when M > N
    // If M = N = 4000, then total iterations ≈ 4000*4001/2 ≈ 8e6, which is close.

    N = 4000;
    M = 4000;
}