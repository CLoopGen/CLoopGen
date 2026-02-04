#include <stddef.h>
#include <stdint.h>
#include <stdlib.h>

size_t src_size1;
size_t i;

void init_vars() {
    src_size1 = 64 * 1024 * 1024; // 64 million iterations to target ~0.01 sec on modern CPUs
}