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
    // Values are set at compile time to ensure loop runs ~0.01 seconds
    // With M=N=8192, total iterations is ~67M, which is sufficient
}