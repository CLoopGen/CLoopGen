#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef int x86_reg;

x86_reg i;

void init_vars() {
    // No additional initialization needed for scalar loop index
    // Loop runs 64 iterations (8*8), which is negligible in execution time.
    // Since there are no arrays or memory accesses in the loop,
    // no large data allocations are required.
    // The loop itself will execute far below 0.01 seconds,
    // but without memory operations or work inside the loop body,
    // we cannot meaningfully extend its runtime.
    // Thus, only initialize the index variable as needed.
    i = 0;
}