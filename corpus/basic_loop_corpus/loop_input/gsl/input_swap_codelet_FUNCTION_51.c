#include <stddef.h>
#include <stdint.h>
#include <stdlib.h>

size_t dest_size1;
size_t dest_size2;
size_t i;

void init_vars() {
    // Assuming a typical modern CPU can handle around 10^8 operations per second
    // We want the loop to run in approximately 0.01 seconds, so target ~10^6 iterations
    // The total number of iterations is dest_size1 * dest_size2
    // Choose sizes such that the product is about 1e6 to get desired runtime

    dest_size1 = 1000;
    dest_size2 = 1000;
}