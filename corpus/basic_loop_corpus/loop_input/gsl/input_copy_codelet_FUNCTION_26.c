#include <stddef.h>
#include <stdint.h>
#include <stdlib.h>

size_t src_size1;
size_t i;

void init_vars() {
    src_size1 = 64000000;  // Adjusted to target ~0.01s runtime on modern CPU
}