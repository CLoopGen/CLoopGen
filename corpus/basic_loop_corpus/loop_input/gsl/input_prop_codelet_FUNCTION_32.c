#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

size_t size1;
size_t size2;
size_t i;
size_t j;

void init_vars() {
    // Assuming the loop is meant to process a significant amount of data
    // but does no actual memory operations — we choose sizes to make the loop
    // run for approximately 0.01 seconds on a modern CPU.

    // A double loop with empty body: performance depends on number of iterations.
    // Typical modern CPU can do ~1e9 simple operations per second.
    // We aim for roughly 10 million iterations to account for loop overhead and target ~0.01 sec.

    size1 = 3000;
    size2 = 3000;
}