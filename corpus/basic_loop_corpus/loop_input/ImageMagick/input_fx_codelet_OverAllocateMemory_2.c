#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

size_t length = 1 << 28; // ~268 million to ensure loop runs ~0.01s
size_t extent;

void init_vars() {
    extent = 0;
}