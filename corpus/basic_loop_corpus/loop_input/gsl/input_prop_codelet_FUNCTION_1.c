#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

size_t size1;
size_t size2;
size_t i;
size_t j;

void init_vars() {
    // Assuming the loop should perform a significant amount of iterations
    // to take around 0.01 seconds on a modern CPU.
    // A double loop with ~65536 * 4096 iterations can take approximately that long
    // depending on optimization, but we choose sizes to avoid overflow and ensure duration.

    // Set sizes to create a total iteration count in the tens of millions range
    size1 = 8192;   // Outer loop count
    size2 = 4096;   // Inner loop count
}