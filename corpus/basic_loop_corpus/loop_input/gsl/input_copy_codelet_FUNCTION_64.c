#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

size_t M = 10000;
size_t N = 20000;
size_t i;
size_t j;

void init_vars() {
    // No dynamic allocation or complex initialization needed for this loop
    // since the loop only uses scalar indices and has no array accesses.
    // The values of M and N are chosen to make the double loop run approximately 0.01 seconds.
    // Empirical tuning suggests that with M=10000 and N=20000, the number of iterations is about:
    // sum_{i=0}^{M-1} max(0, N - (i+1)) ≈ M*N - M*(M+1)/2 ≈ 10000*20000 - 50e6 = 150e6 iterations,
    // which on a modern CPU with simple empty loop takes around tens of milliseconds.
}