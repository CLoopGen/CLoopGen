#include <stddef.h>
#include <stdint.h>
#include <stdlib.h>

size_t dest_size1;
size_t dest_size2;
size_t i;

void init_vars() {
    // Aim for approximately 0.01 seconds of computation
    // The inner loop is empty, so we can afford relatively large sizes.
    // On a modern CPU, a billion iterations might take around 0.1-1 second,
    // so we aim for about 10-50 million total iterations to stay within 0.01s.

    dest_size1 = 5000;
    dest_size2 = 2000;
}