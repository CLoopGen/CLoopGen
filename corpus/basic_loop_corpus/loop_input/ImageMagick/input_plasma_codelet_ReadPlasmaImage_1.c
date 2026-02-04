#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

size_t i;
size_t max_depth;

void init_vars() {
    i = (size_t)1 << 30;  // Large value to ensure loop runs for many iterations
}