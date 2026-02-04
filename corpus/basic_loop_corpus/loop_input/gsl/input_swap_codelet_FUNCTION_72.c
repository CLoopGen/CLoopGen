#include <stddef.h>
#include <stdint.h>
#include <stdlib.h>

size_t dest_size1;
size_t dest_size2;
size_t i;

void init_vars() {
    // Aim for approximately 0.01 seconds of computation
    // The inner loop runs dest_size1 * dest_size2 times
    // Assuming ~1e9 iterations per second on modern CPU, target ~1e7 total iterations
    // Choose sizes to achieve this without exceeding memory bounds

    dest_size1 = 4096;
    dest_size2 = 4096;
}