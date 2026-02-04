#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

size_t size1;
size_t p;

void init_vars() {
    // Assuming a moderate data size to make the loop run ~0.01 seconds
    // Modern CPUs can handle millions of iterations in milliseconds.
    // Using 16 million iterations as a reasonable estimate for ~0.01 sec
    size1 = 16000000;  // 16e6 iterations
}