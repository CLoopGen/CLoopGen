#include <stddef.h>
#include <stdint.h>
#include <stdlib.h>

size_t dest_size1;
size_t dest_size2;
size_t i;

void init_vars() {
    // Aim for approximately 0.01 seconds of runtime
    // The inner loop is empty, so we can use relatively large sizes
    // Modern CPUs can handle millions of iterations in milliseconds

    dest_size1 = 10000;   // Outer loop count
    dest_size2 = 10000;   // Inner loop count
}