#include <stddef.h>
#include <stdint.h>
#include <stdlib.h>

size_t dest_size1;
size_t dest_size2;
size_t i;

void init_vars() {
    // Aim for approximately 0.01 seconds of computation
    // The loop has two levels: i in [0, dest_size1) and j in [0, dest_size2)
    // Total iterations = dest_size1 * dest_size2
    // On a modern CPU, each iteration is very lightweight (just increment checks)
    // Assume ~1e9 iterations per second -> target ~1e7 iterations for 0.01s

    dest_size1 = 4000;
    dest_size2 = 2500;  // ~10 million total iterations
}