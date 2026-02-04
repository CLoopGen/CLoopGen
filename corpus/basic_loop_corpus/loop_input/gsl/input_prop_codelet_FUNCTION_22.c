#include <stddef.h>
#include <stdint.h>
#include <stdlib.h>

size_t size1;
size_t size2;
size_t i;
size_t j;

void init_vars() {
    // Assuming the loop is intended to process data with reasonable memory footprint
    // and given no explicit array, we choose sizes so that the double loop takes ~0.01s
    // Modern CPUs can do billions of operations per second, so aim for ~10M-100M iterations

    size1 = 3000;
    size2 = 3000;
}