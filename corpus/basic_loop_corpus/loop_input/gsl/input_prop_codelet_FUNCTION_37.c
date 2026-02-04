#include <stddef.h>
#include <stdint.h>
#include <stdlib.h>

size_t size1;
size_t size2;
size_t i;
size_t j;

void init_vars() {
    // Assuming typical modern CPU can handle ~1e8 operations per second
    // Aim for loop iterations to take ~0.01 seconds -> ~1e6 to 1e7 total iterations
    // Choose sizes to result in about 10 million iterations: size1 * size2 ≈ 10^7
    size1 = 3162;  // approx sqrt(10e6)
    size2 = 3162;
}