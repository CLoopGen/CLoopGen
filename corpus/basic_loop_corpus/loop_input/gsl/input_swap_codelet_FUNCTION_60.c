#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

size_t K = 10000;
size_t i;
size_t j;

void init_vars() {
    // No additional initialization needed for scalar variables
    // K is set to 10000 to ensure the double loop runs approximately 50 million iterations,
    // which is sufficient to take around 0.01 seconds on modern CPUs without any heavy operations.
}