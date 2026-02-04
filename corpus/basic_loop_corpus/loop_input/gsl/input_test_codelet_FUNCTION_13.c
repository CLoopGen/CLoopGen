#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

size_t i;

void init_vars() {
    // No additional initialization needed for scalar variables
    // Loop bounds are self-contained and do not depend on external data
    // The loop runs for a fixed count (1027 iterations), independent of data size
    // No arrays or heap allocations required based on the empty loop body
}
// No main function included as per instructions