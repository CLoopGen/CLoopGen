#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

size_t M = 8192;
size_t N = 8192;
size_t tda_a = 8192;
size_t tda_b = 8192;
size_t i;
size_t j;

void init_vars() {
    // No dynamic initialization needed for scalar variables
    // All sizes are set to ensure ~67M iterations, which is sufficient
    // to take around 0.01 seconds on modern CPUs when compiled with optimization
}