#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

size_t M = 131072;
size_t N = 131072;
size_t i;

void init_vars() {
    // No additional initialization needed for scalar variables
    // Data size chosen to achieve approximately 0.01 seconds of runtime
    // Assuming typical modern CPU can handle this loop in the order of nanoseconds per iteration
    // 131072 iterations should be sufficient to reach desired runtime
}