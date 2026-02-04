#include <stddef.h>
#include <stdint.h>
#include <stdlib.h>

size_t size1;
size_t size2;
size_t i;
size_t j;

void init_vars() {
    // Estimate data sizes to achieve ~0.01 seconds of execution
    // Typical modern CPU can handle billions of iterations per second,
    // so we choose moderate sizes to avoid excessive runtime.

    // The loop has O(size1 * size2) complexity.
    // To run for about 0.01 seconds, assume a modern CPU can do ~1e9 loops/sec => ~1e7 loops in 0.01s.
    // We aim for around 1e7 total iterations.

    size1 = 3000;
    size2 = 3000;
}