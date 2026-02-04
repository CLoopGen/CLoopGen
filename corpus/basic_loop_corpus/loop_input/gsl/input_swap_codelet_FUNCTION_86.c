#include <stddef.h>
#include <stdint.h>
#include <stdlib.h>

size_t dest_size1;
size_t dest_size2;
size_t i;

void init_vars() {
    // Aim for approximately 0.01 seconds of computation
    // The inner loop is empty, so we can afford larger sizes.
    // On a modern CPU, millions of iterations per second are typical.
    // Set dest_size1 and dest_size2 such that total iterations ~10^7 to 10^8.

    dest_size1 = 10000;
    dest_size2 = 10000;
}