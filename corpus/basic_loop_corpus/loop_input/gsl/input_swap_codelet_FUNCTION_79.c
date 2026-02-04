#include <stddef.h>
#include <stdint.h>
#include <stdlib.h>

size_t dest_size1;
size_t dest_size2;
size_t i;

void init_vars() {
    // Aim for approximately 0.01 seconds of runtime
    // The inner loop has no body, so we can use relatively large sizes
    // to simulate computational intensity when compiled with optimizations

    // Adjust sizes so that total iterations ~ 1e8 to 1e9 for ~0.01s on modern CPU
    dest_size1 = 10000;
    dest_size2 = 10000;
}