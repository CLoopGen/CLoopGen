#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

size_t size1;
size_t p;

void init_vars() {
    // Assuming a data size that would make the loop run about 0.01 seconds
    // Modern CPUs can do billions of operations per second, so a moderate array size is sufficient
    // Since the loop body is empty except for local variable declarations,
    // we choose size1 such that the loop overhead takes ~0.01s.
    // A few hundred million iterations might take ~0.01s depending on CPU.

    size1 = 25000000;  // 25 million iterations should be around 0.01s on most modern systems
}