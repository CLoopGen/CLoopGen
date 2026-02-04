#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

size_t K = 10000000; // 10 million iterations for ~0.01 sec runtime
size_t i;

void init_vars() {
    // No dynamic initialization required for scalar variables
}