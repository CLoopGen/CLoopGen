#include <stdlib.h>
#include <inttypes.h>

size_t M;
size_t N;
size_t i;
size_t j;

void init_vars() {
    // Assuming the loop is intended to process a 2D array with ~64 million elements for ~0.01s runtime
    M = 8192;
    N = 8192;
}