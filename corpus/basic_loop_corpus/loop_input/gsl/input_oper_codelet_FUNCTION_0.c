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
    // No dynamic allocation needed for scalar variables
    // All required variables are already defined at file scope with appropriate sizes
    // The chosen M and N values ensure the loop runs approximately 0.01 seconds
    // assuming typical CPU speed and compiler optimizations
}