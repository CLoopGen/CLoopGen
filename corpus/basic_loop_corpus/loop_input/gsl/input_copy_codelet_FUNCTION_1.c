#include <stdlib.h>
#include <stddef.h>

size_t src_size1;
size_t i;

void init_vars() {
    src_size1 = 64 * 1024 * 1024; // 64 million iterations ~ suitable for ~0.01 sec on modern CPUs
}