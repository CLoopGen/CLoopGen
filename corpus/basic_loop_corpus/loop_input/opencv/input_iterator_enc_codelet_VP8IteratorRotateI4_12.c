#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int i;

void init_vars() {
    // No additional initialization needed for scalar variables
    // The loop uses only the global int i, which is already defined
    // Loop bounds are fixed (0 to 2), so no data size tuning required
    i = 0; // Ensure proper initial state
}