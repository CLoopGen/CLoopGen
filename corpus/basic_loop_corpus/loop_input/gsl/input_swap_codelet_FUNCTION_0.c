#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

size_t size1 = 67108864; // 64M elements * sizeof(size_t) = 512MB, sufficient for ~0.01s workload
size_t p;

void init_vars() {
    // No dynamic initialization needed; all variables are file-scope globals with static initialization
}