#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

size_t M = 10000;
size_t N = 20000;
size_t i;
size_t j;

void init_vars() {
    // No additional initialization needed for scalar variables
    // Values of M and N are chosen to create sufficient loop iterations
    // to achieve approximately 0.01 seconds of execution time
}