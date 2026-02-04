#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

size_t i;
size_t m = 10000000; // Sufficient to run loop for ~0.01 seconds on modern CPU

void init_vars() {
    // No additional initialization needed for scalar variables
    // i is loop counter, initialized in loop
    // m is set to appropriate size
}