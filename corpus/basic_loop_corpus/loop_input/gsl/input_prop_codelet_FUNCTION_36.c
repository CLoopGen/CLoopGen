#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

size_t size1;
size_t size2;
size_t i;
size_t j;

void init_vars() {
    // Assuming the loop is intended to process a 2D data structure
    // Targeting ~0.01 seconds on a modern CPU: aim for roughly 10-100 million iterations
    // A 10,000 x 10,000 loop gives 100 million iterations, which is reasonable
    size1 = 10000;
    size2 = 10000;
}