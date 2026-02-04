#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

size_t i;

void init_vars() {
    // No additional initialization needed for scalar loop index
    // The loop uses only 'i' which is a simple size_t counter
    // Memory access bounds are not present in the loop body
    // Loop runs 1027 iterations, no data array required for timing
    // Using minimal data since loop has no memory operations
}
// No main function included as per instructions