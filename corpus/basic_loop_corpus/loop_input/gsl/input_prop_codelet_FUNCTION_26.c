#include <stdlib.h>
#include <stddef.h>

size_t size1;
size_t size2;
size_t i;
size_t j;

void init_vars() {
    // Assuming a typical modern CPU can handle ~1e8 iterations per second,
    // set sizes so that total iterations are around 1e6 to 1e7 for ~0.01 sec
    size1 = 32768;  // outer loop count
    size2 = 32;     // inner loop count (total: ~1.05e6 iterations)
}

// Explicit instantiation of all extern variables at file scope
size_t size1;
size_t size2;
size_t i;
size_t j;