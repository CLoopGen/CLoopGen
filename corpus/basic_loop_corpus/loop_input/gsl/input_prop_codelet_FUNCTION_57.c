#include <stddef.h>
#include <stdint.h>
#include <stdlib.h>

size_t size1;
size_t size2;
size_t i;
size_t j;

void init_vars() {
    // Assuming the loop is intended to process a 2D array with total data around 64MB
    // to achieve approximately 0.01 seconds runtime on modern CPUs.
    size1 = 8192;        // Outer loop iterations
    size2 = 8192;        // Inner loop iterations
}