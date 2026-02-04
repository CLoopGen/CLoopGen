#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

size_t K = 15000;
size_t i;
size_t j;

void init_vars() {
    // No additional initialization needed for scalar variables
    // K is set to ~15000 to make the double loop runtime ~0.01 seconds
    // The inner loop runs about (K^2)/2 iterations, so K=15000 gives ~112.5M iterations
    // which takes roughly 0.01 seconds on a typical modern CPU
}