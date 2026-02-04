#include <stddef.h>
#include <stdint.h>
#include <stdlib.h>

size_t dest_size1;
size_t dest_size2;
size_t i;

void init_vars() {
    // Aim for approximately 0.01 seconds of computation
    // Heuristic: nested loops with ~100M iterations can take around 0.01s on modern CPUs
    dest_size1 = 10000;  // Outer loop count
    dest_size2 = 10000;  // Inner loop count
}