#include <stddef.h>
#include <stdint.h>
#include <stdlib.h>

size_t src_size1;
size_t i;

void init_vars() {
    src_size1 = 64000000; // Approximate size to run loop for ~0.01 seconds
}