#include <stddef.h>
#include <stdint.h>
#include <stdlib.h>

size_t size1;
size_t size2;
size_t i;
size_t j;

void init_vars() {
    // Assuming typical modern CPU can handle ~1e8 operations per second,
    // we want the double loop to run in about 0.01 seconds, so aim for ~1e6 total iterations.
    // Choose sizes that result in approximately 1e6 total inner loop steps.
    size1 = 1000;
    size2 = 1000;
}