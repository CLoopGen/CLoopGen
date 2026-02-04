#include <stddef.h>
#include <stdint.h>
#include <stdlib.h>

size_t dest_size1;
size_t dest_size2;
size_t i;

void init_vars() {
    // Assuming typical modern CPU can handle ~1M iterations in ~0.01s in tight loop
    // Since inner loop is empty, we choose sizes to roughly match time target
    // Using approx 16k x 16k = 256M iterations as heavy loop count for timing
    dest_size1 = 16384;
    dest_size2 = 16384;
}