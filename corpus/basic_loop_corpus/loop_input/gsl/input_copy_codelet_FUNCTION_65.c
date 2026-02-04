#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

size_t M = 131072;
size_t N = 131072;
size_t i;

void init_vars() {
    // No additional initialization needed for scalar variables
    // M and N are already initialized to create a loop of ~131k iterations
    // which is tuned to run about 0.01 seconds on modern CPUs
}