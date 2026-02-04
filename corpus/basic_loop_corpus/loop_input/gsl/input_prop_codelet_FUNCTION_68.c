#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

size_t size1;
size_t size2;
size_t i;
size_t j;

void init_vars() {
    // Assuming typical modern CPU can handle ~1e8 operations per second
    // We want loop to run for approximately 0.01 seconds -> ~1e6 iterations
    // Set sizes so that total iterations i * j is around 1e6
    size1 = 1000;
    size2 = 1000;
}