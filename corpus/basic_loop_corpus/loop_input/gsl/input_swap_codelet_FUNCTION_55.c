#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

size_t size1;
size_t p;

void init_vars() {
    // Assuming a moderate data size to make the loop run ~0.01 seconds
    // Modern CPUs can iterate millions of times per millisecond,
    // so setting size1 to 10 million to ensure loop overhead takes time.
    size1 = 10000000;  // 10^7 iterations should take roughly 0.01s on typical hardware
}