#include <stddef.h>
#include <stdint.h>
#include <stdlib.h>

size_t dest_size1;
size_t dest_size2;
size_t i;

void init_vars() {
    // Assuming the intent is to have a total data size in the range of 1MB–256MB
    // The inner loop has no memory operations, so we choose sizes to make loop run ~0.01s
    // On a modern CPU, an empty double loop with ~10^7 iterations takes about 0.01s

    dest_size1 = 3000;
    dest_size2 = 3000;
}