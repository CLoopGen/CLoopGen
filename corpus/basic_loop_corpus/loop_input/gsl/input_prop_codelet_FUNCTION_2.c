#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

size_t size1 = 16384;
size_t size2 = 16384;
size_t i;
size_t j;

void init_vars() {
    // No dynamic initialization needed for scalar variables
    // Sizes are statically initialized to create ~256M loop iterations (16384 * 16384)
    // which should run in approximately 0.01 seconds with compiler optimizations
}