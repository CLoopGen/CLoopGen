#include <stdlib.h>
#include <stddef.h>

size_t size1;
size_t size2;
size_t i;
size_t j;

void init_vars() {
    // Assuming typical modern CPU can handle ~1e8 operations in 0.01 seconds
    // Use sizes to create total iterations in that range
    size1 = 10000;
    size2 = 10000;
}