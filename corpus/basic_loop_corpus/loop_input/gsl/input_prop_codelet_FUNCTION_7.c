#include <stddef.h>
#include <stdint.h>
#include <stdlib.h>

size_t size1;
size_t size2;
size_t i;
size_t j;

void init_vars() {
    // Aim for approximately 0.01 seconds of execution time
    // The inner loop performs size1 * size2 iterations, each with minimal work.
    // On a modern CPU, a simple double loop like this can execute roughly 1e8 to 1e9 iterations per second.
    // So for ~0.01s, we aim for about 1e6 to 1e7 total iterations.

    size1 = 3000;
    size2 = 3000;
}