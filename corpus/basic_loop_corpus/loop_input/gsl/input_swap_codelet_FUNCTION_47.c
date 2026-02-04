#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <time.h>

size_t K;
size_t i;

void init_vars() {
    // Estimate iterations to achieve ~0.01 seconds runtime
    // Assume modern CPU can do ~1e9 iterations per second -> ~1e7 in 0.01s
    K = 10000000;  // 10 million iterations for ~0.01 sec
}

// Separate function to force compiler not to optimize loop away
void __attribute__((noinline)) touch(volatile void *ptr) {
    *(volatile char*)ptr = *(volatile char*)ptr;
}