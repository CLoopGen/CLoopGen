#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

size_t size1;
size_t p;

void init_vars() {
    // Assuming a moderate data size to make the loop run ~0.01 seconds
    // Modern CPUs can iterate millions of times per millisecond,
    // so we choose size1 such that total iterations are in the range
    // of tens to hundreds of millions for measurable duration.
    // Based on typical performance, 50 million iterations ≈ ~0.01 sec

    size1 = 50000000;  // 50 million iterations
}