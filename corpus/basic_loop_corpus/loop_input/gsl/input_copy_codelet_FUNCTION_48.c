#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

size_t M = 15000;
size_t N = 15000;
size_t i;
size_t j;

void init_vars() {
    // No dynamic allocation or further initialization needed for scalar loop bounds
    // Values of M and N are chosen to make the double loop take ~0.01 seconds
    // Inner loop executes min(i, N) times per outer iteration
    // Total iterations ≈ sum_{i=1}^{M-1} min(i, N)
    // With M = N = 15000, total iterations ≈ (M-1)*(M)/2 ≈ 112.5M, which is sufficient
}