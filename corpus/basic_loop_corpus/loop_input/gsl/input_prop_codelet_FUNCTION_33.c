#include <stddef.h>
#include <stdint.h>
#include <stdlib.h>

size_t size1 = 16384;
size_t size2 = 16384;
size_t i;
size_t j;

void init_vars() {
    // No dynamic initialization required for scalar variables
    // Sizes are statically initialized to achieve ~0.01s runtime
    // Assuming two nested loops with empty body, adjust sizes to avoid excessive time
    // Product of size1 and size2 should be around 10^8 iterations for ~0.01s on modern CPU
    size1 = 10000;
    size2 = 10000;
}