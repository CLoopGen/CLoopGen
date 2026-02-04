#include <stddef.h>
#include <stdint.h>
#include <stdlib.h>

size_t dest_size1;
size_t dest_size2;
size_t i;

void init_vars() {
    // Aim for approximately 0.01 seconds of computation
    // The inner loop has no body, so we estimate based on typical loop overhead.
    // Aiming for around 10-20 million total iterations to take ~0.01s on modern CPUs.

    dest_size1 = 4096;
    dest_size2 = 4096;
}