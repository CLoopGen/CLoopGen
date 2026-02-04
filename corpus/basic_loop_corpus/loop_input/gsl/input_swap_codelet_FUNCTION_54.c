#include <stdlib.h>
#include <stdint.h>

size_t K;
size_t i;

void init_vars() {
    // Assuming typical modern CPU can handle ~1e8 operations in 0.01 seconds
    // Set K to 10 million iterations for a tight loop to last ~0.01 seconds
    K = 10000000;
}