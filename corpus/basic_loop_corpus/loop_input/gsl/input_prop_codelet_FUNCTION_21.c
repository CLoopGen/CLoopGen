#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <time.h>

size_t size1;
size_t size2;
size_t i;
size_t j;

void init_vars() {
    // Estimate iterations to achieve ~0.01 seconds runtime
    // Assume modern CPU can handle about 1e9 simple operations per second
    // So for 0.01 seconds, aim for about 1e7 total iterations (i * j)

    size1 = 3200;
    size2 = 3200;
}

// Initialize at file scope if needed; here we use init_vars for flexibility
static void __attribute__((constructor)) initialize() {
    init_vars();
}