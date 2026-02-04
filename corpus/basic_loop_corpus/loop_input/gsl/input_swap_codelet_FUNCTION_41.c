#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

size_t size1;
size_t p;

void init_vars() {
    // Assuming the loop body implies usage of arrays or data structures
    // Since no explicit memory access is shown, we assume size1 should be set
    // to a value that makes the loop run for ~0.01 seconds.
    //
    // On a modern CPU, a simple loop with empty body can run ~1e9 iterations per second.
    // So for 0.01 sec, we use ~10 million iterations.
    
    size1 = 10000000;  // 10^7 iterations ≈ 0.01 sec
}