#include <stddef.h>
#include <stdint.h>
#include <stdlib.h>

size_t size1;
size_t size2;
size_t i;
size_t j;

void init_vars() {
    // Assuming typical modern CPU can handle ~1e8 operations in 0.01 seconds
    // The double loop has size1 * size2 iterations.
    // Set total iterations to about 10 million to stay within time and avoid heavy memory use.
    size1 = 3162;  // ~sqrt(10e6)
    size2 = 3162;
}