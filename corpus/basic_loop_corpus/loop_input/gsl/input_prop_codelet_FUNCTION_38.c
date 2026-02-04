#include <stddef.h>
#include <stdint.h>
#include <stdlib.h>

size_t size1;
size_t size2;
size_t i;
size_t j;

void init_vars() {
    // Assuming a typical modern CPU can handle around 10^8 operations per second,
    // we aim for total iterations to take about 0.01 seconds -> ~10^6 to 10^7 iterations.
    // We choose sizes such that size1 * size2 is about 10 million (1e7).
    size1 = 3162;  // approx sqrt(10e6)
    size2 = 3162;
}